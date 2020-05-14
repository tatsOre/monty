#include "monty.h"

/**
 * op_pall - Prints all the values on the stack starting from the TOS
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)(line_number);

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;

		if (current == *stack) /* curr reaches circular head */
			return;
	}
}
