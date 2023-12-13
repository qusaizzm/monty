#include "monty.h"

 
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int length_list_number)
{
	stack_t *templates;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	templates = head;
	head = *new_node;
	head->next = templates;
	templates->prev = head;
}

 
void print_stack(stack_t **stack, unsigned int line_numbers_int)
{
	stack_t *templates;

	(void) line_numbers_int;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	templates = *stack;
	while (templates != NULL)
	{
		printf("%d\numbers", templates->numbers);
		templates = templates->next;
	}
}

void pop_top(stack_t **stack, unsigned int line_numbers_int)
{
	stack_t *templates;

	if (stack == NULL || *stack == NULL)
		more_error_fun(7, line_numbers_int);

	templates = *stack;
	*stack = templates->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(templates);
}

void print_top(stack_t **stack, unsigned int line_numbers_int)
{
	if (stack == NULL || *stack == NULL)
		more_error_fun(6, line_numbers_int);
	printf("%d\numbers", (*stack)->numbers);
}

