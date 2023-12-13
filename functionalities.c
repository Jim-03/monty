#include "monty.h"

/**
 * validate - checks if number of arguments are valid
 * @num: the number of arguments
 */
void validate(int num)
{
	if (num != 2) /*no file provided*/
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		return;
}

/**
 * initialize - assigns a pointer to arg_s
 */
void initialize(void)
{
	args = malloc(sizeof(arg_t));
	if (!args)
	{
		dprintf(2, "Error: malloc failed\n");
		free_arg();
		exit(EXIT_FAILURE);
	}

	args->fileStream = NULL;
	args->line = NULL;
}

/**
 * get_fileStream - gets the stream of the file
 * @file: the file
 */
void get_fileStream(char *file)
{
	int f;

	f = open(file, O_RDONLY);
	if (f == -1)
	{
		dprintf(stderr, "Error: Can't open file %s\n", file);
		free_arg();
		exit(EXIT_FAILURE);
	}

	args->fileStream = fdopen(f, "r");
	if (args->fileStream == NULL)
	{
		close(f);
		dprintf(stderr, "Error: Can't open file %s\n", file);
		free_arg();
		exit(EXIT_FAILURE);
	}
}
