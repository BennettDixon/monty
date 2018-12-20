/*
 * File: stack.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
	{
		malloc_error();
		return (EXIT_FAILURE);
	}

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}
