#include "monty.h"

/**
 * pchar_error - Prints error messages for monty_pchar.
 * @line_number: The current working line number of a Monty bytecodes file.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
