#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * free_s - list holding variables to free
 * @new: struct stack_t pointer
 * @line: char pointer
 * @arguments: char double pointer
 * @fd: file descriptor
*/
typedef struct free_s
{
	stack_t *new;
	char *line;
	char **arguments;
	FILE *fd;
} free_t;
free_t struct_t;

/**
 * number_s - list holding the number after a bytcode op
 * @number: number after bytecode op
*/
typedef struct number_s
{
	int number;
} n_t;
n_t number_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* GLOBAL VARIABLE */
extern int number;

/* execution function */
void _exec(char *str, stack_t **head, unsigned int line_number);

/* functions isntructions */
void push(stack_t **head,  unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);

/* FUNCTION PROTOTYPES */
char **valid_arguments(char **arguments, int line_number);
void interpretation(FILE *fd);
char **tokenize(char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
int extend(char *str);
int stack_len(stack_t *head);
void free_dlistint(stack_t **head);
void free_close(free_t struct_t, stack_t **head);
#endif