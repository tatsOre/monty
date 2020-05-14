#include "monty.h"

/**
 * op_pint - Prints the value at the TOS, followed by a new line
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
