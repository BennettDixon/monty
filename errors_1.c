/*
 * File: errors_1.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

void usage_error(void);
void f_open_error(char *filename);
void malloc_error(void);
void unknown_op_error(char *opcode, unsigned int line_number);
void no_int_error(unsigned int line_number);

/**
 * usage_error - Prints usage error messages.
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

/**
 * f_open_error - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open.
 */
void f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
}

/**
 * malloc_error - Prints malloc error messages.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	set_op_tok_error();
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 */
void unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	set_op_tok_error();
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 */
void no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	set_op_tok_error();
}
