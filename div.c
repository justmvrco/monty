#include "monty.h"

/**
  * div_ - divides the second top element of the stack by
  * the top elem of stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void div_(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i = 0, j = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	i = temp->n;
	j = (*stack)->n;
	if (i == 0)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = j / i;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  * mul - multiplies the second top element of the stack with the
  * top element of the stack.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void.
  */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  * mod - computes the modulus of the second top element of the stack
  * by the top element of the stack.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void.
  */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
