#include "deck.h"

/**
 * custom_strcmp - Compare two strings without using strcmp
 * @str1: First string
 * @str2: Second string
 * Return: Integer less than, equal to, or greater than zero if str1 is found,
 * respectively, to be less than, to match, or be greater than str2.
 */
int custom_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
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
	int i, value_a, value_b;
	const card_t *card_a = (*(const deck_node_t **)a)->card;
	const card_t *card_b = (*(const deck_node_t **)b)->card;
	const char *order[] = {"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"};

	if (card_a->kind != card_b->kind)
		return (card_a->kind - card_b->kind);

	value_a = 0;
	value_b = 0;

	for (i = 0; i < 13; i++)
	{
		if (custom_strcmp(card_a->value, order[i]) == 0)
			value_a = i;

		if (custom_strcmp(card_b->value, order[i]) == 0)
			value_b = i;
	}

	return (value_a - value_b);
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
