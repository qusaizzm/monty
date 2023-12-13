#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

 
typedef struct stack_s
{
        int numbers;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
 
typedef struct instruction_s
{
        char *openscode;
        void (*f)(stack_t **stack, unsigned int line_numbers_int);
} instruction_t;

extern stack_t *head;
typedef void (*opens_funs)(stack_t **, unsigned int);

/*file operations*/
void open_files_funs(char *files_name_to_open);
int parse_line(char *buffer, int line_numbers_int, int format_int);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int numbers);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(opens_funs, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void s_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void adds_node(stack_t **, unsigned int);
void subsc_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void models_nodes(stack_t **, unsigned int);

/*String operations*/
void print_char_string(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rtolre(stack_t **, unsigned int);

/*Error hanlding*/
void errorcode(int error_code, ...);
void more_error_fun(int error_code, ...);
void string_error_funs(int error_code, ...);
void rtorle(stack_t **, unsigned int);

#endif

