/*
 * File: monty_funcs_1.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"
#include <stdio.h>

void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);

/**
 * monty_stack - Converts a queue to a stack.
 * @stack: A pointer to the bottom (queue) of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	*stack = tmp;

	(void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue.
 * @stack: A pointer to the top (stack) of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	*stack = tmp;
	(void)line_number;
}

/**
 * monty_pall - Prints a stack_t linked list.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
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
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int value;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		malloc_error();
		return;
	}

	if (op_toks[1] == NULL)
	{
		no_int_error(line_number);
		return;
	}

	value = atoi(op_toks[1]);
	if (value == 0 && *op_toks[1] != '0')
	{
		no_int_error(line_number);
		return;
	}
	new->n = value;

	if (!stack || !(*stack) || (*stack)->prev == NULL) /* STACK mode */
	{
		if (!stack || !(*stack))
			tmp = NULL;
		else
			tmp = *stack;
		new->prev = NULL;
		new->next = tmp;
		if (tmp != NULL)
			tmp->prev = new;
	}
	else /* QUEUE mode */
	{
		tmp = *stack;
		new->next = NULL;
		new->prev = tmp;
	}
	*stack = new;
}

/**
 * monty_pop - removes the top element of the stack or the queue
 *
 * @stack: stack to remove value from, can be stack or queue
 * @line_number: line number opcode was present in script.
 * Used for debugging.
 *
 * Return: always void
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL, *tmp = NULL;

	if (!stack || !(*stack))
	{
		pop_error(line_number);
		return;
	}
	else if ((*stack)->prev == NULL) /* STACK MODE */
	{
		next = (*stack)->next;
		free(*stack);
		if (next)
			next->prev = NULL;
		*stack = next;
	}
	else /* QUEUE MODE */
	{
		tmp = *stack;
		/* ADVANCE POINTER TO HEAD INSTEAD OF TAIL */
		while (tmp->prev)
			tmp = tmp->prev;
		next = tmp->next;
		free(tmp);
		if (next)
			next->prev = NULL;
	}
}
