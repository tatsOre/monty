#include "monty.h"

/**
 * op_swap - Swaps the top two elements of the stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (st_data.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	node = (*stack)->next;
	node->prev = (*stack)->prev; /* NULL if len == 2*/
	(*stack)->prev = node;
	(*stack)->next = node->next; /* NULL if len == 2*/
	node->next->prev = (*stack);
	node->next = (*stack);
	*stack = node;
}
