#include "monty.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * usage_error - prints usage error and returns error code
 *
 * Return: (EXIT_FAILURE) always
 */
int usage_error(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error information and returns error code
 *
 * Return: (EXIT_FAILURE) always
 */
int malloc_error(void)
{
	write(STDERR_FILENO, "Error: malloc failed\n", 21);
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints file open error w/ file name
 * @filename: name of file failed to open
 *
 * Return: (EXIT_FAILURE) always
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file <%s>\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - prints the unknown opcode error to STDERR
 * @opcode: opcode where error occured
 * @line_number: line number in script where error occured
 *
 * Return: (EXIT_FAILURE) always
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%<%u>: unknown instruction <%s>\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints the invalid argument provided error
 * @line_number: line in script error occured on
 *
 * Return: (EXIT_FAILURE) always
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
