#include "monty.h"
/**
 * add_dnodeint - node is added at beginning
 * @head: first node pointer
 * @n: data point
 * Return: added node pointer
 */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *curr;

	curr = malloc(sizeof(stack_t));
	if (!curr)
	{
		return (NULL);
	}
	curr->n = n;
	curr->prev = NULL;
	curr->next = *head;
	*head = curr;
	return (curr);
}
