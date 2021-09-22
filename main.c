#include "monty.h"

/**
  * main - entry point.
  * @argc: argument count.
  * @argv: argument vector.
  *
  * Return: 0.
  */
int main(int argc, char **argv)
{
	FILE *fptr;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int line_c = 1;
	char **tk = NULL, *line = NULL;
	void (*op_func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		err(1);
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
		err(2, argv[1]);
	while (getline(&line, &size, fptr) != -1)
	{
		if (!strcmp(line, "\n") || *line == '#')
		{
			line_c++;
			continue;
		}
		tk = break_line(line), op_func = get_opcode(tk[0]);
		if (op_func == NULL)
			free_dlist(stack), err(3, line_c, tk[0], tk, line);
		if (strcmp(tk[0], "push") == 0 && tk[1])
		{
			if (toInt(tk[1]) >= 0)
				argument = toInt(tk[1]);
			else
			{
				free(line), free(tk), fclose(fptr), free_dlist(stack);
				err(5, line_c);
			}
		}
		if (!strcmp(tk[0], "push") && !tk[1])
			free(line), free(tk), fclose(fptr), free_dlist(stack), err(5, line_c);
		op_func(&stack, line_c), line_c++, free(tk);
	}
	fclose(fptr), free(line), free_dlist(stack);
	return (0);
}
