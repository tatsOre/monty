#include "monty.h"

/**
 * op_push - Pushes a node on top of stack
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	char *push_arg = NULL;
	int n = 0;

	push_arg = strtok(NULL, "\r\n\t ");
	if (!push_arg || _is_number(push_arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(push_arg);
	if (add_node(stack, n) == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	st_data.stack_len++;
}

/**
 * _is_number - Checks if push arg is a valid argument
 * @p_arg: push opcode argument
 * Return: Always 1 (Success), Fail (0)
 */
int _is_number(char *p_arg)
{
	int i = 0;

       	if (p_arg[i] == '-' || p_arg[i] == '+')
       		i++;

	while (p_arg[i])
	{
		if (isdigit(p_arg[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
