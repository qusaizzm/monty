#include "monty.h"

 
void nop(stack_t **stack, unsigned int line_numbers_int)
{
	(void)stack;
	(void)line_numbers_int;
}

 
void s_nodes(stack_t **stack, unsigned int line_numbers_int)
{
	stack_t *templates;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error_fun(8, line_numbers_int, "swap");
	templates = (*stack)->next;
	(*stack)->next = templates->next;
	if (templates->next != NULL)
		templates->next->prev = *stack;
	templates->next = *stack;
	(*stack)->prev = templates;
	templates->prev = NULL;
	*stack = templates;
}

 
void adds_node(stack_t **stack, unsigned int line_numbers_int)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error_fun(8, line_numbers_int, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->numbers + (*stack)->prev->numbers;
	(*stack)->numbers = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

 
void subsc_nodes(stack_t **stack, unsigned int line_numbers_int)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error_fun(8, line_numbers_int, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->numbers - (*stack)->prev->numbers;
	(*stack)->numbers = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

 
void div_nodes(stack_t **stack, unsigned int line_numbers_int)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error_fun(8, line_numbers_int, "div");

	if ((*stack)->numbers == 0)
		more_error_fun(9, line_numbers_int);
	(*stack) = (*stack)->next;
	sum = (*stack)->numbers / (*stack)->prev->numbers;
	(*stack)->numbers = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

