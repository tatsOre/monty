#include "monty.h"

/**
 * op_stack - Sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program
 * When switching mode:
 * The top of the stack becomes the front of the queue
 * The front of the queue becomes the top of the stack
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
