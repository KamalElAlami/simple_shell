#include "main.h"

/**
 * main - Entry point for the simple shell program
 *
 * This is the main function of a simple shell program. It repeatedly
 * reads input lines, tokenizes them into commands, and executes the
 * commands. The program continues to run until an exit condition is met.
 *
 * @ac: The number of command-line arguments (unused in this context).
 * @av: An array of command-line arguments (unused in this context).
 *
 * Return: The exit status of the shell program.
 */

int	main(int ac, char **av)
{
	char *line;
	char **cmd;
	int stts, cnter;
	(void) ac;

	line = NULL;
	cmd = NULL;
	stts = 0;
	cnter = 0;
	while (1)
	{
		line = track_lines();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (stts);
		}
		cnter++;

		cmd = tokenize(line);
		if (cmd == NULL)
		{
			continue;
		}
		stts = _exec(cmd, av, cnter);
	}
}
