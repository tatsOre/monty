#include "monty.h"

/**
 * op_pop - Removes the top element of the stack
 * @stack: entry point into the stack circular list
 * @line_number: opcode line number
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (st_data.stack_len == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if (st_data.stack_len > 1)
	{
		(*stack)->next->prev = (*stack)->prev; /* points to last */
		(*stack)->prev->next = (*stack)->next;
		(*stack) = (*stack)->next;
	}
	else
		(*stack) = NULL;

	free(node);
	st_data.stack_len--;
}
