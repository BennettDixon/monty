#include "monty.h"
#include <string.h>

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
 * @script_fd: file descriptor for script that is open, to be read
 * and processed
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
	int i = 0, read = -1;

	while ("C is awesome")
	{
		line = NULL;
		read = getline(&line, &len, script_fd);
		if (read == -1)
		{
			free(line);
			if (line && line[0] == 0)
				break;
			return (malloc_error());
		}
		op_toks = strtow(line, " \n\t\a\b");
		free(line);
		if (op_toks == NULL)
			return (malloc_error());

		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
			return (unknown_op_error(op_toks[0], line_number));

		op_func(&stack, line_number);
		line_number++;
		i = 0;
		while(op_toks[i])
		{
			if (op_toks[i])
				free(op_toks[i]);
			i++;
		}
		free(op_toks);
	}

	return (EXIT_SUCCESS);
}
