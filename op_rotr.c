#include "monty.h"

/**
 * op_rotr - Rotates the stack to the bottom. The last element of the stack
 * becomes the top element of the stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);

	if (*stack)
		*stack = (*stack)->prev;
}
