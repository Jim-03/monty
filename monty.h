#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arg_s - structure to hold variables
 * @fileStream: the stram of a file
 * @line: line read from fileStream
 * @count: the line number
 */
typedef struct arg_s
{
	FILE *fileStream;
	char *line;
	unsigned int count;
	int wordCount;
	char **someWords;
	instruction_t *cmd;
} arg_t;

extern arg_t *args;
int main(int argc, char **argv);
void validate(int num);
void initialize(void);
void get_fileStream(char *file);
void cleanup(void);
void readAndPrintLines(void);
void line_to_words(void);

#endif
