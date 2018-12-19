#include "monty.h"

/**
 * monty_nop - does absolutely nothing for the opcode 'nop'
 * @stack: stack, needed for get_op_func()
 * @line_number: line number nop located at in script,
 * needed for get_op_func()
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}


void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		pint_error(line_number);
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
