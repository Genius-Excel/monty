#include "monty.h"

/**
 * sub - subtracts the top element of a stack from the second top
 * @stack: stack which operation is to be done.
 * @line_number: line number which elements is to be subtracted.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*(*stack)).next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*(*stack)).n;

	/*Call the pop function on the stack*/
	pop(stack, line_number);
}

/**
* op_div - subtracts the top element of a stack from the second top
* @stack: stack which operation is to be done.
* @line_number: line number which element is to be divided.
*/
void op_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*(*stack)).next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*(*stack)).n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*(*stack)).next->n /= (*(*stack)).n;

	/*call the pop function on the stack*/
	pop(stack, line_number);
}
