#include "monty.h"

/**
 * op_queue - Sets the format of the data to a queue (FIFO)
 * When switching mode:
 * The top of the stack becomes the front of the queue
 * The front of the queue becomes the top of the stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	(void)(stack);

	st_data.mode = QUEUE;
}
