#include "monty.h"

 
void print_char_string(stack_t **stack, unsigned int line_numbers_int)
{
	int asciiv_int;

	if (stack == NULL || *stack == NULL)
		string_error_funs(11, line_numbers_int);

	asciiv_int = (*stack)->numbers;
	if (asciiv_int < 0 || asciiv_int > 127)
		string_error_funs(10, line_numbers_int);
	printf("%c\numbers", asciiv_int);
}

void print_str(stack_t **stack, __attribute__((unused))unsigned int length_list_number)
{
	int asciiv_int;
	stack_t *templates;

	if (stack == NULL || *stack == NULL)
	{
		printf("\numbers");
		return;
	}

	templates = *stack;
	while (templates != NULL)
	{
		asciiv_int = templates->numbers;
		if (asciiv_int <= 0 || asciiv_int > 127)
			break;
		printf("%c", asciiv_int);
		templates = templates->next;
	}
	printf("\numbers");
}

void rtolre(stack_t **stack, __attribute__((unused))unsigned int length_list_number)
{
	stack_t *templates;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	templates = *stack;
	while (templates->next != NULL)
		templates = templates->next;

	templates->next = *stack;
	(*stack)->prev = templates;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

void rtorle(stack_t **stack, __attribute__((unused))unsigned int length_list_number)
{
	stack_t *templates;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	templates = *stack;

	while (templates->next != NULL)
		templates = templates->next;

	templates->next = *stack;
	templates->prev->next = NULL;
	templates->prev = NULL;
	(*stack)->prev = templates;
	(*stack) = templates;
}

