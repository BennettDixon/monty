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
