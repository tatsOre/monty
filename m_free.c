#include "monty.h"

/**
 * m_free_list - Frees st_data.stack
 * Return: void
 */
void m_free_list(void)
{
	stack_t *node = NULL;

	while (st_data.stack)
	{
		node = st_data.stack;
		st_data.stack = st_data.stack->next;
		free(node);
	}
}

/**
 * m_fs_close - Close stream file
 * Return: void
 */
void m_fs_close(void)
{
	fclose(st_data.stream);
}

/**
 * m_free_line - Free getline buffer line variable
 * Return: void
 */
void m_free_line(void)
{
	if (st_data.line)
		free(st_data.line);
}
