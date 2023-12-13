#include "monty.h"
#include <stdio.h>
/**
 * main - the start point
 * @argc: number of arguments passed
 * @argv: array of argc
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void) argv; /*unused*/

	validate(argc);
	initialize();
	get_fileStream(argv[1]);
	readAndPrintLines();
	cleanup();
	return (0);
}
