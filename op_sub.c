#include "monty.h"

/**
 * op_sub - Subtracts the TOS from the second top element of the stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	if (st_data.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	op_pop(stack, line_number);
}
