#include "monty.h"

/**
 * op_swap - Swaps the top two elements of the stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int fn, sn;

	if (st_data.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	fn = (*stack)->n;
	sn = (*stack)->next->n;
	(*stack)->n = sn;
	(*stack)->next->n = fn;
}
