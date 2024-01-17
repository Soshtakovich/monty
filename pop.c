#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the Monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;

if (temp->next != NULL)
temp->next->prev = NULL;

*stack = temp->next;
free(temp);
}
