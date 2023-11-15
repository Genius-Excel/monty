#include "monty.h"

/**
 * push - this function push an element to a stack.
 * @stack: pointer to the stack element is to be pushed.
 * @line_number: line number at which the functon is to be executed.
 * Return: void.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *opcode_val;

	int opcode_int_val;

	stack_t *head_node;

	opcode_val = strtok(NULL, " \n\t");

	opcode_int_val = atoi(opcode_val);

	/*This condition checks if argument to push is a valid integer*/
	if (opcode_val == NULL || !is_a_number(opcode_val))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	head_node = malloc(sizeof(stack_t));

	if (head_node == NULL)
	{
		fprintf(stderr, "Malloc failed.\n");
		exit(EXIT_FAILURE);
	}

	(*head_node).n = opcode_int_val;

	(*head_node).prev = NULL;

	(*head_node).next = *stack;

	if (*stack != NULL)
	{
		(*(*stack)).prev = head_node;
	}

	*stack = head_node;
}


/**
 * pall - this function prints all the elements in a stack to stdout.
 * @stack: stack of linked list.
 * @line_number: number on the file which the element is to be printed from.
 * Return: void.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;

	while (head != NULL)
	{
		printf("%d\n", (*head).n);

		head = (*head).next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = first->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (second->next != NULL)
		second->next->prev = first;
	first->next = second->next;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}
