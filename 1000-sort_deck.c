#include "deck.h"

/**
 * compare_cards - Comparison function for qsort
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 * Return: Difference in values
 */
static int compare_cards(const void *a, const void *b)
{
    return (*((const card_t **)a))->value[0] - (*((const card_t **)b))->value[0];
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t i;
    deck_node_t *current;
    const card_t *cards[52];

    if (deck == NULL || *deck == NULL)
        return;

    current = *deck;
    i = 0;

    /* Extract cards from the deck and store in an array */
    while (current != NULL)
    {
        cards[i] = current->card;
        current = current->next;
        i++;
    }

    /* Use qsort to sort the array of cards */
    qsort(cards, i, sizeof(card_t *), compare_cards);

    /* Re-link the sorted cards back to the deck */
    current = *deck;
    for (i = 0; i < 52; i++)
    {
        current->card = cards[i];
        current = current->next;
    }
}
