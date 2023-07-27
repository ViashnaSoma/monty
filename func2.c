#include "monty.h"

/**
 * _add - first 2 items in stack are added
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *sec, *first;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		sec = first->next;
		first->n = first->n + sec->n;
		first->next = sec->next;
		free(sec);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		global_vars.opcode_err = 1;
	}
}

/**
 * _nop - none
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	if (stack && line_number)
	{
		line_number++;
	}
}

/**
 * _sub - first 2 items in stack are subtracted
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _sub(stack_t **stack, unsigned int line_number)
{
        stack_t *sec, *first;

        if (*stack && (*stack)->next)
        {
                first = *stack;
                sec = first->next;
                first->n = first->n - sec->n;
                first->next = sec->next;
                free(sec);
        }
        else
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                global_vars.opcode_err = 1;
        }
}

/**
 * _div - first two items in stack are divided
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _div(stack_t **stack, unsigned int line_number)
{
        stack_t *sec, *first;

        if (*stack && (*stack)->next)
        {
                first = *stack;
                sec = first->next;
                first->n = first->n / sec->n;
                first->next = sec->next;
                free(sec);
        }
        else
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
                global_vars.opcode_err = 1;
        }
}

/**
 * _mul - first two items in stack are multiplied
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _mul(stack_t **stack, unsigned int line_number)
{
        stack_t *sec, *first;

        if (*stack && (*stack)->next)
        {
                first = *stack;
                sec = first->next;
                first->n = first->n * sec->n;
                first->next = sec->next;
                free(sec);
        }
        else
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                global_vars.opcode_err = 1;
        }
}

/**
 * _mod - first two items in stack mod
 * @stack: first element in stack pointer
 * @line_number: code line number
 * Return: no return value
 */
void _mod(stack_t **stack, unsigned int line_number)
{
        stack_t *sec, *first;

        if (*stack && (*stack)->next)
        {
                first = *stack;
                sec = first->next;
                first->n = first->n % sec->n;
                first->next = sec->next;
                free(sec);
        }
        else
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
                global_vars.opcode_err = 1;
        }
}
