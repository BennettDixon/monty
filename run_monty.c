/*
 * File: run_monty.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"
#include <string.h>

void free_tokens(void);
void free_stack(stack_t **stack);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

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
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"stack", monty_stack},
		{"queue", monty_queue},
		{"push", monty_push},
		{"pall", monty_pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_monty - primary function to execute a monty script currently open
 * @script_fd: file descriptor for script that is open,
 *             to be read and processed
 *
 * Return: (EXIT_SUCCESS) on success, respective error code on failure
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	void (*op_func)(stack_t**, unsigned int);

	while (getline(&line, &len, script_fd) != -1)
	{
		op_toks = strtow(line, " \n\t\a\b");
		if (op_toks == NULL)
		{
			free(line);
			free_stack(&stack);
			return (malloc_error());
		}

		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free(line);
			free_tokens();
			free_stack(&stack);
			return (unknown_op_error(op_toks[0], line_number));
		}

		op_func(&stack, line_number);
		line_number++;
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (EXIT_SUCCESS);
}
