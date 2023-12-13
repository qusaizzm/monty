#include "monty.h"
stack_t *head = NULL;
 

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\numbers");
		exit(EXIT_FAILURE);
	}
	open_files_funs(argv[1]);
	free_nodes();
	return (0);
}

 
stack_t *create_node(int numbers)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errorcode(4);
	node->next = NULL;
	node->prev = NULL;
	node->numbers = numbers;
	return (node);
}

 
void free_nodes(void)
{
	stack_t *templates;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		templates = head;
		head = head->next;
		free(templates);
	}
}

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int length_list_number)
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
	while (templates->next != NULL)
		templates = templates->next;
	templates->next = *new_node;
	(*new_node)->prev = templates;

}

