#include "deck.h"

/**
 * compare_strings - Compare two strings
 * @str1: First string
 * @str2: Second string
 * Return: Integer less than, equal to, or greater than zero if str1 is found,
 * respectively, to be less than, to match, or be greater than str2.
 */
int compare_strings(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

/**
 * compare_cards - Compare two cards for sorting
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 * Return: Integer less than, equal to, or greater than zero if a is found,
 * respectively, to be less than, to match, or be greater than b.
 */
int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;

    if (card_a->kind != card_b->kind)
        return card_a->kind - card_b->kind;

    /* Special handling for "Ace" and "10" values */
    if (card_a->value[0] == 'A' && card_b->value[0] == '1')
        return 1;  /* "Ace" comes after "10" */
    else if (card_a->value[0] == '1' && card_b->value[0] == 'A')
        return -1; /* "10" comes before "Ace" */

    return compare_strings(card_a->value, card_b->value);
}

/**
 * sort_deck - Sorts a deck of cards in ascending order.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
    size_t deck_size = 52;
    deck_node_t *deck_array[52];
    deck_node_t *current = *deck;
    size_t i;

    if (!deck || !*deck || deck_size < 2)
        return;

    for (i = 0; i < deck_size; i++)
    {
        deck_array[i] = current;
        current = current->next;
    }

    qsort(deck_array, deck_size, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < deck_size - 1; i++)
    {
        deck_array[i]->next = deck_array[i + 1];
        deck_array[i + 1]->prev = deck_array[i];
    }

    deck_array[0]->prev = NULL;
    deck_array[deck_size - 1]->next = NULL;

    *deck = deck_array[0];
}

