#include "monty.h"

/**
 * op_div - Divides the second top elm of the stack by the top elm of the stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	if (st_data.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	op_pop(stack, line_number);
}
