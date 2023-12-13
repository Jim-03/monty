#include "monty.h"

/**
 * line_to_words - tokenizes line into words
 */
void line_to_words(void)
{
	int i = 0;
	char *delimiter = ' \n';
	char *word = NULL;
	char * copied_line = NULL;

	copied_line = malloc(sizeof(char) * (_strlenstrlen(args->line) + 1));
	if (!copied_line)
	{
		perror("Error: malloc failed\n");
		free_args();
		exit(EXIT_FAILURE);
	}
	_strcpy(copied_line, args->line);
	args->wordCount = 0;
	word = strtok(copied_line, delimiter);
	while (word)
	{
		args->wordCount++;
		word = strtok(NULL, delimiter);
	}

	args->someWords = malloc(sizeof(char *) * (args->wordCount + 1));
	_strcpy(copied_line, args->line);
	word = strtok(copied_line, delimiter);
	while (word)
	{
		args->someWords[i] = malloc(sizeof(char) * (_strlen(word) + 1));
		if (!args->someWords[i])
		{
			dprintf(2, "Error: malloc failed\n");
			free_args();
			exit(EXIT_FAILURE);
		}
		_strcpy(args->someWords[i], word);
		word = strtok(NULL, delimiter);
		i++;
	}
	args->someWords[i] = NULL;
	free(copied_line);
}
