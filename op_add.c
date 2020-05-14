#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int add = 0;

	if (st_data.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	add = (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n += add;
}
