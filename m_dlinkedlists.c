#include "monty.h"

/**
 * add_node - Adds a new node at the top of stack
 * @stack: entry point into the circular doubly linked list
 * @n: value to add to the new node
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node = NULL;

	if (!stack)
		return (NULL);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	if (*stack == NULL) /* Adding first elm */
	{
		new_node->prev = new_node; /* same */
		new_node->next = new_node; /* Points to itself */
	}
	else /* if stack_len > 0 */
	{
		(*stack)->prev->next = new_node;  /*last node points to new */
		new_node->prev = (*stack)->prev;  /* points to last node */
		(*stack)->prev = new_node;
		new_node->next = (*stack);
	}
/*If stack is empty or list is in stack mode, new is head */
	if (st_data.stack_len == 0 || st_data.mode == STACK)
		(*stack) = new_node;

	return (new_node);
}
