#include "monty.h"

/**
 * op_stack - Sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	(void)(stack);

	st_data.mode = STACK;
}
