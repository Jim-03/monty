#include "monty.h"

/**
 * validate - checks if number of arguments are valid
 * @num: the number of arguments
 */
void validate(int num)
{
	if (num != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * initialize - assigns a pointer to arg_s
 */
void initialize(void)
{
	args = malloc(sizeof(arg_t));
	if (args == NULL)
	{
		perror("Error: malloc failed");
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
	int file_descriptor = open(file, O_RDONLY);

	if (file_descriptor == -1)
	{
		perror("Error: Can't open file");
		free_arg();
		exit(EXIT_FAILURE);
	}

	args->fileStream = fdopen(file_descriptor, "r");
	if (args->fileStream == NULL)
	{
		perror("Error: Can't open file");
		close(file_descriptor);
		free_arg();
		exit(EXIT_FAILURE);
	}
}

/**
 * readAndPrintLines - reads a line and prints it
 */
void readAndPrintLines(void)
{
	while (getline(&args->line, &n, args->fileStream) != -1)
	{
		printf("%s", args->line);
		line_to_words();
	}
}

/**
 * cleanup - Close the file stream and free allocated memory
 */
void cleanup(void)
{
	fclose(args->fileStream);
	free_arg();
}

