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
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue.
 * @stack: A pointer to the top (stack) of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
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
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
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
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
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
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
