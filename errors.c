#include "monty.h"

/**
  * err - switches between the error codes, variadic func.
  * @code: the code to be printed.
  *
  * Return: void.
  */
void err(int code, ...)
{
	va_list ag;
	char *opc;
	int line_num;

	va_start(ag, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
			break;
		case 3:
			line_num = va_arg(ag, int);
			opc = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opc);
			free(va_arg(ag, char **));
			free(va_arg(ag, char *));
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	va_end(ag);
	exit(EXIT_FAILURE);
}
