#include "monty.h"

/**
 * enqueue - adds an element at the end
 * @n: data to add
 */
void enqueue(int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		global.quit = EXIT_FAILURE;
		return;
	}
	new->n = n;
	if (!global.head)
	{
		global.head = global.tail = new;
	}
	else if (global.head == global.tail)
	{
		global.head->next = new;
		new->prev = global.head;
	}
	else
	{
		global.tail->next = new;
		new->prev = global.tail;
	}
	global.tail = new;
}

/**
 * dequeue - remove element in FIFO
 * Return: data of element removed
 */
int dequeue(void)
{
	return (pop());
}

/**
 * print_queue - print in FIFO
 */

void print_queue(void)
{
	print_stack();
}
