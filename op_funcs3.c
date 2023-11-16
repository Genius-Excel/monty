#include "monty.h"
/**
 * sub - subtracts the top element of a stack from the second top
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't sub, stack too short");

		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;

	pop(stack, line_number); /* to pop the top element*/
}
