#include "monty.h"

/**
 * op_pstr - Prints the string starting at the TOS, followed by a new line.
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	int ch = 0;
	stack_t *current = *stack;
	(void)(line_number);

	while (current)
	{
		ch = current->n;

		if (ch <= 0 || ch > 127)
			break;

		putchar(ch);
		current = current->next;

		if (current == *stack) /* check circ list */
			break;
	}
	putchar('\n');
}
