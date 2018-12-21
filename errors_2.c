/*
 * File: errors_2.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

void pop_error(unsigned int line_number);
void pint_error(unsigned int line_number);
void short_stack_error(unsigned int line_number, char *op);
void div_error(unsigned int line_number);
void pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 */
void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	set_op_tok_error();
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 */
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	set_op_tok_error();
}

/**
 * short_stack_error - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 */
void short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	set_op_tok_error();
}

/**
 * div_error - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 */
void div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	set_op_tok_error();
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 */
void pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	set_op_tok_error();
}
