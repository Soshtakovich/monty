#define _GNU_SOURCE
#include "monty.h"

/**
* main - main initiation function of monty
* @argc: number of arguments
* @argv: actual arguments
* Return: Exit Success
*/
int main(int argc, char *argv[])
{
FILE *file;
stack_t *stack;
char *line;
size_t len;
unsigned int line_number;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");

if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

stack = NULL;

line = NULL;
len = 0;
line_number = 0;

while (getline(&line, &len, file) != -1)
{
line_number++;
execute_opcode(&stack, line, line_number);
}

fclose(file);
free(line);
free_stack(&stack);

return (EXIT_SUCCESS);
}

/**
* execute_opcode - execute the monty program
* @stack: pointer to the top of the stack
* @line: line
* @line_number: line number in the Monty file
*/
void execute_opcode(stack_t **stack, char *line, unsigned int line_number)
{
char *opcode;
opcode = strtok(line, " \n");
if (opcode == NULL || opcode[0] == '#')
return;

if (strcmp(opcode, "push") == 0)
{
push(stack, line_number);
}
else if (strcmp(opcode, "pop") == 0)
pop(stack, line_number);
else if (strcmp(opcode, "pint") == 0)
pint(stack, line_number);
else if (strcmp(opcode, "pall") == 0)
pall(stack, line_number);
else if (strcmp(opcode, "swap") == 0)
swap(stack, line_number);
else if (strcmp(opcode, "add") == 0)
add(stack, line_number);
else if (strcmp(opcode, "nop") == 0)
nop(stack, line_number);
else if (strcmp(opcode, "mul") == 0)
mul(stack, line_number);
else if (strcmp(opcode, "sub") == 0)
sub(stack, line_number);
else if (strcmp(opcode, "div") == 0)
_div(stack, line_number);
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
