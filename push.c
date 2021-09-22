#include "monty.h"

/**
  * push - push data to top of stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_number;
	if (new_node != NULL)
	{
		new_node->n = argument;
		new_node->prev = NULL;
		new_node->next = NULL;

		if (*stack == NULL)
			*stack = new_node;
		else
		{
			new_node->next = *stack;
			(*stack)->prev = new_node;
			*stack = new_node;
		}
	}
	else
	{
		free_dlist(*stack);
		free(new_node);
		err(4);
	}
}

/**
  * pop - removes the element at the top of the stack
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack != NULL && (*stack)->next == NULL)
	{
		temp = *stack;
		free(temp);
		*stack = NULL;
	}
	else if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * swap - swaps the top two elements of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
  * add - adds the top two elements of the stack.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void.
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp->n + temp->next->n;
	free(temp);
}

/**
  * sub - subtracts the top element of the stack from the second top element.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp->next->n - temp->n;
	free(temp);
}
