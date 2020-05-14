#include "monty.h"

/**
 * op_rotl - Rotates the stack to the top. The top element of the stack becomes
 * the last one, and the second top element of the stack becomes the first one
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);

	if (*stack)
		*stack = (*stack)->next;
}
