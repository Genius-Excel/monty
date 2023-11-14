#include "monty.h"

/**
 * push - pushes stack elements to the top of the stack
 * @n: data of the element to be pushed
 */
void push(int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");

		exit(EXIT_FAILURE);
	}

	newnode->n = n;
	newnode->next = top;  // Link new node to the current top
	newnode->prev = NULL;  // Since it's the new top, its previous is NULL

	if (top != NULL)
	{
		top->prev = newnode;  // Update the previous of the old top
	}

	top = newnode;  // Update the top to the new node
}

