/*
 * File: stack.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int is_stack(stack_t **stack);

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = NULL, *iter = NULL;

	if (stack && *stack)
	{
		tmp = *stack;
		if ((*stack)->next == NULL) /* queue */
		{
			while (tmp)
			{
				iter = tmp->prev;
				free(tmp);
				tmp = iter;
			}
		}
		else /* normal stack */
		{
			while (tmp)
			{
				iter = tmp->next;
				free(tmp);
				tmp = iter;
			}
		}
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
	stack_t *s, *q;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());
	q = malloc(sizeof(stack_t));
	if (q == NULL)
	{
		free(s);
		return (malloc_error());
	}

	s->n = STACK;
	s->prev = NULL;
	s->next = q;
	q->n = QUEUE;
	q->next = NULL;
	q->prev = s;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * is_stack - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - 1.
 *         Otherwise - 0.
 */
int is_stack(stack_t **stack)
{
	if ((*stack)->n == STACK && (*stack)->prev == NULL)
		return (1);
	return (0);
}
