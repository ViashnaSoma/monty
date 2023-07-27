#include "monty.h"

glob_t global_vars;

/**
 * execute_opcode -each line is tokenised to get opcode
 * @code_line: code line
 * @LIFO: head of stack
 * @line_number: code line number
 * Return: positive for success, negative for failure
 */
int execute_opcode(char *code_line, stack_t **LIFO, unsigned int line_number)
{
	const char *space = " ";
	char *opcode;
	void (*f)(stack_t **, unsigned int);

	opcode = strtok(code_line, space);
	opcode[strcspn(opcode, "\n")] = 0;
	if (!(f = valid_opcode(opcode)))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}
	global_vars.opcode_arg = strtok(NULL, space);
	global_vars.opcode_err = 0;
	f(LIFO, line_number);
	if (global_vars.opcode_err)
		return (-1);
	return (1);
}

/**
 * valid_opcode - checks if opcode is a valid command
 * @opcode - opcode string
 * Return: the function to execute opcode
 */
void (*valid_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, 
		{"swap", _swap}, {"add", _add}, 
		{"nop", _nop}, {"sub", _sub},
		{"mul", _mul}, {"div", _div},
		{"mod", _mod}, {NULL, NULL},
	};
	int num = 0;

	while(opcodes[num].opcode)
	{
		if (strcmp(opcodes[num].opcode, opcode) == 0)
		{
			return (opcodes[num].f);
		}
		num++;
	}
	return (opcodes[num].f);
}
