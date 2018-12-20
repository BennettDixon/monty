/*
 * File: errors_2.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);

/**
 * short_stack_error - Prints error messages for calls to monty math functions
 *                     with stacks/queues smaller than two nodes.
 * @line_number: The current working line number of a monty opcodes file.
 * @op: The operation calling the error.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L<%u>: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints error message for call to monty_div
 *             with a top element of 0.
 * @line_number: The current working line number of a monty opcodes file.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pop_error - Prints the error message for call to monty_pop
 * @line_number: line number in script that error occured
 *
 * Return: (EXIT_FAILURE) always
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints the error message for monty_pint
 * @line_number: The line number in a Monty bytecodes
 *               where the error occured.
 *
 * Return: (EXIT_FAILURE) always
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * set_op_tok_error - sets last element of op_toks to be an error code
 * @error_code: integer to store as a string in op_toks
 *
 * Return: always void
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
