#include "monty.h"

void open_files_funs(char *files_name_to_open)
{
	FILE *filedirct = fopen(files_name_to_open, "r");

	if (files_name_to_open == NULL || filedirct == NULL)
		errorcode(2, files_name_to_open);

	read_file(filedirct);
	fclose(filedirct);
}

void read_file(FILE *filedirct)
{
	int line_numbers_int, format_int = 0;
	char *buffer = NULL;
	size_t length_list = 0;

	for (line_numbers_int = 1; getline(&buffer, &length_list, filedirct) != -1; line_numbers_int++)
	{
		format_int = parse_line(buffer, line_numbers_int, format_int);
	}
	free(buffer);
}

int parse_line(char *buffer, int line_numbers_int, int format_int)
{
	char *openscode, *value;
	const char *delim = "\numbers ";

	if (buffer == NULL)
		errorcode(4);

	openscode = strtok(buffer, delim);
	if (openscode == NULL)
		return (format_int);
	value = strtok(NULL, delim);

	if (strcmp(openscode, "stack") == 0)
		return (0);
	if (strcmp(openscode, "queue") == 0)
		return (1);

	find_func(openscode, value, line_numbers_int, format_int);
	return (format_int);
}
 
void find_func(char *openscode, char *value, int length_list_number, int format_int)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", s_nodes},
		{"add", adds_node},
		{"sub", subsc_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", models_nodes},
		{"pchar", print_char_string},
		{"pstr", print_str},
		{"rtolre", rtolre},
		{"rtorle", rtorle},
		{NULL, NULL}
	};

	if (openscode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].openscode != NULL; i++)
	{
		if (strcmp(openscode, func_list[i].openscode) == 0)
		{
			call_fun(func_list[i].f, openscode, value, length_list_number, format_int);
			flag = 0;
		}
	}
	if (flag == 1)
		errorcode(3, length_list_number, openscode);
}

void call_fun(opens_funs func, char *opracations_str, char *val, int length_list_number, int format_int)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opracations_str, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errorcode(5, length_list_number);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errorcode(5, length_list_number);
		}
		node = create_node(atoi(val) * flag);
		if (format_int == 0)
			func(&node, length_list_number);
		if (format_int == 1)
			add_to_queue(&node, length_list_number);
	}
	else
		func(&head, length_list_number);
}

