/*
 * File: monty_funcs_2.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Adds the top two elements of a stack.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 *
 * Description: The result is stored in the second node from the top
 *              and the top node is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	tmp = (*stack)->next;
	tmp->next->n += tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
	free(tmp);
}

/**
 * monty_sub - Subtracts the top element of a stack from the
 *             second element from the top.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 *
 * Description: The result is stored in the second node from the top
 *              and the top is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	tmp = (*stack)->next;
	tmp->next->n -= tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
	free(tmp);
}

/**
 * monty_div - Divides the second element from the
 *             top of a stack by the top element.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 *
 * Description: The result is stored in the second node from the top
 *              and the top is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	tmp = (*stack)->next;
	if (tmp->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	tmp->next->n /= tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
	free(tmp);
}

/**
 * monty_mul - Multiplies the second element from the
 *             top of a stack with the top element.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 *
 * Description: The result is stored in the second node from the top
 *              and the top is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	tmp = (*stack)->next;
	tmp->next->n *= tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
	free(tmp);
}

/**
 * monty_mod - Computes the modulus of the second element
 *             from the top of a stack by the top element.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 * @line_number: The current working line number of a monty opcodes file.
 *
 * Description: The result is stored in the second node from the top
 *              and the top is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	tmp = (*stack)->next;
	if (tmp->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	tmp->next->n %= tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
	free(tmp);
}
