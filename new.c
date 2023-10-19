#include "monty.h"

/**
 * push_handler - push operation
 * @s: pointer to stack
 * @l: line number
 */
void push_handler(stack_t **s, unsigned int l)
{
	int n;
	(void)s;
	(void)l;

	if (!global.arg || !is_number(global.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	n = atoi(global.arg);
	if (global.mode == STACK)
		push(n);
	else
		enqueue(n);
}

/**
 * pop_handler - pop operation
 * @s: pointer to stack
 * @l: line number
 */
void pop_handler(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;

	if (!global.head)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	if (global.mode == STACK)
		pop();
	else
		dequeue();
}

/**
 * swap_handler - swap operation
 * @s: pointer to stack
 * @l: line number
 */
void swap_handler(stack_t **s, unsigned int l)
{
	(void)s;
	if (!global.head || !global.head->next)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	swap();
}

/**
 * pall_handler - pall operation
 * @s: pointer to stack
 * @l: line number
 */
void pall_handler(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;

	if (global.mode == QUEUE)
		print_queue();
	else
		print_stack();
}

/**
 * nop_handler - nop operation
 * @s: pointer to stack
 * @l: line number
 */
void nop_handler(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;
}

/**
 * add_handler - add operation
 * @s: pointer to stack
 * @l: line number
 */
void add_handler(stack_t **s, unsigned int l)
{
	(void)s;

	calculator('+', "add", l);
}

/**
 * sub_handler - sub operation
 * @s: pointer to stack
 * @l: line number
 */
void sub_handler(stack_t **s, unsigned int l)
{
	(void)s;

	calculator('-', "sub", l);
}

/**
 * mul_handler - mul operation
 * @s: pointer to stack
 * @l: line number
 */
void mul_handler(stack_t **s, unsigned int l)
{
	(void)s;

	calculator('*', "mul", l);
}

/**
 * div_handler - div operation
 * @s: pointer to stack
 * @l: line number
 */
void div_handler(stack_t **s, unsigned int l)
{
	(void)s;

	if (global.head && !global.head->n)
	{
		dprintf(2, "L%u: division by zero\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	calculator('/', "div", l);
}

/**
 * mod_handler - mod operation
 * @s: pointer to stack
 * @l: line number
 */
void mod_handler(stack_t **s, unsigned int l)
{
	(void)s;

	if (global.head && !global.head->n)
	{
		dprintf(2, "L%u: division by zero\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	calculator('%', "mod", l);
}

/**
 * pint_handler - pint operation
 * @s: pointer to stack
 * @l: line number
 */
void pint_handler(stack_t **s, unsigned int l)
{
	(void)s;

	if (!global.head)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	printf("%d\n", global.head->n);
}

/**
 * temp_handler - mode change
 * @s: pointer to stack
 * @l: line number
 */
void temp_handler(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;
}

/**
 * pchr_handler - Prints char in top value
 *               node of a stack_t linked list.
 * @stack: Pointer to top mode node of a stack_t linked list.
 * @line_number: Current working line number of a Monty bytecodes file.
 */
void pchr_handler(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		global.quit = EXIT_FAILURE;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		global.quit = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*stack)->n);
}
