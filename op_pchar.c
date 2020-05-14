#include "monty.h"

/**
 * op_pchar - Prints the char at the top of the stack, followed by a new line
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int ch = 0;

	if (st_data.stack_len == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (ch < 0 || ch > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}
