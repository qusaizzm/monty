#include "monty.h"

void mul_nodes(stack_t **stack, unsigned int line_numbers_int)
{
	int sum_num_int;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error_fun(8, line_numbers_int, "mul");

	(*stack) = (*stack)->next;
	sum_num_int = (*stack)->numbers * (*stack)->prev->numbers;
	(*stack)->numbers = sum_num_int;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

void models_nodes(stack_t **stack, unsigned int line_numbers_int)
{
	int sum_num_int;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error_fun(8, line_numbers_int, "mod");


	if ((*stack)->numbers == 0)
		more_error_fun(9, line_numbers_int);
	(*stack) = (*stack)->next;
	sum_num_int = (*stack)->numbers % (*stack)->prev->numbers;
	(*stack)->numbers = sum_num_int;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

