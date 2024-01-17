#include "monty.h"

/**
* mul - multiplies the top two elements of the stack
* @stack: pointer to the top of the stack
* @line_number: line number in the Monty file
*/
void mul(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n *= (*stack)->n;
pop(stack, line_number);
}

/**
* sub - subtracts the top element from the second top element of the stack
* @stack: pointer to the top of the stack
* @line_number: line number in the Monty file
*/
void sub(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n -= (*stack)->n;
pop(stack, line_number);
}

/**
* _div - divides the second top element by the top element of the stack
* @stack: pointer to the top of the stack
* @line_number: line number in the Monty file
*/
void _div(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n /= (*stack)->n;
pop(stack, line_number);
}
