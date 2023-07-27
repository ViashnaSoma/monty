#include "monty.h"

/**
 * _push - item added to top of the stack
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int oc_argint;
	char *opcode_arg = global_vars.opcode_arg;

	if (!opcode_arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		global_vars.opcode_err = 1;
	}
	if ((oc_argint = atoi(opcode_arg)) == 0 && strcmp(opcode_arg, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		global_vars.opcode_err = 1;
	}
	add_dnodeint(stack, oc_argint);
}

/**
 * _pall - displays stack items
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

        if (*stack && line_number)
	{
		curr = *stack;
		while (curr)
		{
			printf("%d\n", curr->n);
			curr = curr->next;
		}
	}
}

/**
 * _pint - top item from stack is printed
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		global_vars.opcode_err = 1;
	}
}

/**
 * _pop - first item is removed
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *next;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		global_vars.opcode_err = 1;
	}
	else
	{
		curr = *stack;
		next = curr->next;
		if (next)
			next->prev = NULL;
		*stack = next;
		free(curr);
	}
}

/**
 * _swap - first two items in stack are swapped
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *first;

	if (*stack && (*stack)->next)
	{
		curr = *stack;
		first = curr->next;
		first->prev = NULL;
		curr->next = first->next;
		first->next = curr;
		curr->prev = first;
		*stack = first;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		global_vars.opcode_err = 1;
	}
}
