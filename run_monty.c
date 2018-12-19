/*
 * File: run_monty.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"
#include <string.h>

void free_tokens(void);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);
int token_arr_len(void);
void set_op_tok_error(int error_code);

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
		{"pop", monty_pop},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"add", monty_add},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"nop", monty_nop},
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
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 1;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		op_toks = strtow(line, " \n\t\a\b");
		if (op_toks == NULL)
		{
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_tokens();
			free_stack(&stack);
			return (unknown_op_error(op_toks[0], line_number));
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			exit_status = atoi(op_toks[2]);
			free_tokens();
			break;
		}
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
	return (exit_status);
}

/**
 * token_arr_len - gets the length of current op_toks
 *
 * Return: length of current op toks as int.
 */
int token_arr_len(void)
{
	int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
}

/**
 * set_op_tok_error - sets last element of op_toks to be an error code
 * @error_code: integer to store as a string in op_toks
 *
 * Return: always void
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0;
	char *exit_str = NULL;

	toks_len = token_arr_len();
	op_toks = realloc(op_toks, sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		malloc_error();
		return;
	}
	op_toks[toks_len] = exit_str;
	op_toks[toks_len + 1] = NULL;
}
