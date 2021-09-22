#include "monty.h"
/**
  * break_line - brak up the line read.
  * @line: line read.
  *
  * Return: array of strings .
  */
char **break_line(char *line)
{
	char *token = NULL;
	char **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * (sizeof(line) + 1));
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n ");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
  * free_dlist - frees a dlistint_t list.
  * @head: pointer to list;
  *
  * Return: void.
  */
void free_dlist(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
  * toInt - converts a string to an int.
  * @s: string to be converted.
  *
  * Return: number if string is num and -1 other wise.
  */
int toInt(char *s)
{
	int i, sign = 0, offset = 0, num;

	if (s[0] == '-')
		sign = -1;
	if (sign == -1)
		offset = 1;
	else
		offset = 0;
	num = 0;
	for (i = offset; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + s[i] - '0';
		else
			num = -1;
	}
	if (sign == -1)
		num = -num;
	return (num);
}
