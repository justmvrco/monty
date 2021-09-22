#include "monty.h"

/**
  * rotl - rotates the stack to the top.
  * @stack: double pointer to stack.
  * @line_number: number of lins.
  *
  * Return: void.
  */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL) /* to get to the last element of the list */
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
  * rotr - rotates the stack to the bottom.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *b_last, *last;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	b_last = NULL;
	while (last->next != NULL)
	{
		b_last = last;
		last = last->next;
	}
	(*stack)->prev = last;
	last->next = *stack;
	*stack = b_last->next;
	b_last->next = NULL;

}
