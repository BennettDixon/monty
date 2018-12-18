#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);

/**
 * monty_stack - Converts a stack to a queue.
 * @stack: A pointer to the top or bottom of a stack.
 * @line_number: The line number of the opcodes file currently at.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	stack = &tmp;

	(void)line_number;
}

/**
 * monty_queue - Converts a queue to a stack.
 * @stack: A pointer to the top or bottom of a stack.
 * @line_number: The line number of the opcodes file currently at.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	stack = &tmp;

	(void)line_number;
}

/**
 * monty_pall - Prints a stack.
 * @stack: A pointer to the top or bottom of a stack.
 * @line_number: The line number of the opcodes file currently at.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		return;
	tmp = *stack;

	if (tmp->prev == NULL)
	{
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}

	else
	{
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->prev;
		}
	}

	(void)line_number;
}

/**
 * monty_push - Pushes a value to the stack.
 * @stack: A pointer to the top or bottom of a stack.
 * @line_number: The line number of the opcodes file currently at.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int value;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_error();
	
	if (stack && *stack)
	{
		tmp = *stack;
		if (tmp->next == NULL)
		{
			while (tmp->prev != NULL)
				tmp = tmp->prev;
		}
	}
	else
		tmp = NULL;

	if (op_toks[1] == NULL)
		no_int_error(line_number);

	value = atoi(op_toks[1]);
	if (value == 0 && *op_toks[1] != '0')
		no_int_error(line_number);

	new->n = value;
	new->prev = NULL;
	new->next = tmp;
	if (tmp != NULL)
		tmp->prev = new;
	if (!stack || !(*stack) || (*stack)->next != NULL)
		*stack = new;
}
