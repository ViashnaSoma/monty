#include "monty.h"

/**
 * main - monty file reader
 * @argc: arg count
 * @argv: arg array
 * Return: EXIT_FAILURE for failure else 0 for success
 */
int main(int argc, char **argv)
{
	FILE *monty_file;
	const size_t size_line = 300;
	unsigned int line_number = 0;
	int err;
	char *line;
	stack_t *LIFO;
	stack_t *curr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = open_file(argv[1]);
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(size_line);
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	LIFO = NULL;
	while (fgets(line, size_line, monty_file) != NULL)
	{
		line_number++;
		if ((err = execute_opcode(line, &LIFO, line_number)) < 0)
		{
			exit(EXIT_FAILURE);
		}
	}
	if (line)
		free(line);
	fclose(monty_file);
	while (LIFO)
	{
		curr = LIFO;
		LIFO = LIFO->next;
		free(curr);
	}
	return (0);
}

/**
 * open_file - attempts to open a file
 * @filename: name of file
 * Return: file open status
 */
FILE *open_file(char *filename)
{
	return (fopen(filename, "r"));
}
