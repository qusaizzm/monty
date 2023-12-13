#include "monty.h"
 
void errorcode(int error_code, ...)
{
	va_list agramant_list;
	char *opracations_str;
	int lebel_numbers_int;

	va_start(agramant_list, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\numbers");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\numbers",
				va_arg(agramant_list, char *));
			break;
		case 3:
			lebel_numbers_int = va_arg(agramant_list, int);
			opracations_str = va_arg(agramant_list, char *);
			fprintf(stderr, "L%d: unknown instruction %s\numbers", lebel_numbers_int, opracations_str);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\numbers");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\numbers", va_arg(agramant_list, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

 
void more_error_fun(int error_code, ...)
{
	va_list agramant_list;
	char *opracations_str;
	int lebel_numbers_int;

	va_start(agramant_list, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\numbers",
				va_arg(agramant_list, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\numbers",
				va_arg(agramant_list, int));
			break;
		case 8:
			lebel_numbers_int = va_arg(agramant_list, unsigned int);
			opracations_str = va_arg(agramant_list, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\numbers", lebel_numbers_int, opracations_str);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\numbers",
				va_arg(agramant_list, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error_funs - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_error_funs(int error_code, ...)
{
	va_list agramant_list;
	int lebel_numbers_int;

	va_start(agramant_list, error_code);
	lebel_numbers_int = va_arg(agramant_list, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\numbers", lebel_numbers_int);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\numbers", lebel_numbers_int);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

