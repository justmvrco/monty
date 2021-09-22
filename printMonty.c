#include "monty.h"
/**
  * pall - prints all arguments inserted.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
  * pint - prints the value at the top of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * pchar - prints the char at the top of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (*stack == NULL)
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (num >= 0 && num <= 127)
		printf("%c\n", num);
	else
	{
		free_dlist(*stack);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * pstr - prints the string starting at the top of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *temp = *stack;

	(void)line_number;

	if (*stack == NULL)
		printf("\n");
	else
	{
		while (temp != NULL)
		{
			num = temp->n;
			temp = temp->next;
			if (num > 0 && num <= 127)
				printf("%c", num);
			else
				break;
		}
		printf("\n");
	}
}
