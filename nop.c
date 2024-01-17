#include "monty.h"

/**
* nop - does nothing
* @stack: pointer to the top of the stack
* @line_number: line number in the Monty file
*/
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
/* nop does nothing */
}

/**
 * free_stack - frees a stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
stack_t *current = *stack;
stack_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}

*stack = NULL;
}
