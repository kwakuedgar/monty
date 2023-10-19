#include "monty.h"

/**
 * clear_memory - clears memory
 */
void clear_memory(void)
{
	stack_t *temp;

	while (global.head)
	{
		temp = global.head->next;
		free(global.head);
		global.head = temp;
	}
}

/**
 * free_tokenized - frees an array
 * @tokens: array to be freed
 */
void free_tokenized(char **tokens)
{
	int i = 0;

	if (!tokens)
		return;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
