#include "monty.h"

/* Initialize Global Struct = stream, line, stack len, stack */
st_data_var st_data = {NULL, NULL, 0, NULL};

/**
 * main - Monty ByteCodes files interpreter
 * @argc: number of command line arguments
 * @argv: command line arguments
 *
 * Return: (EXIT_SUCCESS) on success or (EXIT_FAILURE) on failure
 */
int main(int argc, char *argv[])
{
	char *op_code = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	st_data.stream = fopen(argv[1], "r");
	if (st_data.stream == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	atexit(m_free_line);
	atexit(m_free_list);
	atexit(m_fs_close);
	while ((nread = getline(&st_data.line, &len, st_data.stream)) != -1)
	{
		line_number++;
		op_code = strtok(st_data.line, "\r\n\t ");
		if (op_code)
			get_op_func(op_code, &st_data.stack, line_number);
	}

	exit(EXIT_SUCCESS);
}

/**
 * get_op_func - Checks for opcode function and executes it
 * @op_code: op code instruction token
 * @stack: entry point into the stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void get_op_func(char *op_code, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t op_list[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"nop", op_nop},
		{"add", op_add},
		{NULL, NULL}
	};

	while (op_list[i].opcode)
	{
		if (strcmp(op_list[i].opcode, op_code) == 0)
		{/* Executes op_function */
			op_list[i].f(stack, line_number);
			return;
		}
		i++;
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
		line_number, op_code);

	exit(EXIT_FAILURE);
}
