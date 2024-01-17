#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
char *arg;
int value;
stack_t *new_node;

arg = strtok(NULL, " \n");

if (arg == NULL || !is_numeric(arg))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(arg);

/* Create a new stack node */

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}

/**
 * pall - prints all values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{

stack_t *current;
(void)line_number; /* Unused parameter */

current = *stack;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * is_numeric - checks if a string is a numeric value
 * @str: string to check
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(char *str)
{
if (*str == '-')
str++;

while (*str)
{
if (!isdigit(*str))
return (0);
str++;
}

return (1);
}
