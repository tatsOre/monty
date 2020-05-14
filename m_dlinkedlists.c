#include "monty.h"

/**
 * add_node - Adds a new node at the top of stack
 * @stack: entry point into the doubly linked list
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
	new_node->next = *stack; /* NULL if !*stack */
	new_node->prev = NULL;
	*stack = new_node;

	if (new_node->next)
		(new_node->next)->prev = new_node;

	return (new_node);
}
