#include "monty.h"

/**
 * op_mul - Multiplies sec top elm of the stack with the top elm of the stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	if (st_data.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	op_pop(stack, line_number);
}
