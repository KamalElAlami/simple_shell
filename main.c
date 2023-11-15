#include "main.h"

/**
 * main - Entry point for the simple shell program
 *
 * @ac: The number of command-line arguments (unused in this context).
 * @av: An array of command-line arguments (unused in this context).
 *
 * Return: The exit status of the shell program.
 */

int main(int argc, char **argv, char **environ)
{
	(void)argc;

	if (isatty(STDIN_FILENO))
		func_loop(environ, argv[0]);
	else
		no_interactive(environ, argv[0]);
	return (0);
}