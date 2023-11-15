#include "main.h"

/**
 * freestrarr - Free memory allocated for an array of strings
 *
 * @array: The array of strings to free.
 */


void	freestrarr(char **array, int i)
{
	int i;

	i = 0;
	if (!array)
		return;
	while (array[i])
	{
		free(array[i]), array[i] = NULL;
		i++;
	}
	free(array), array = NULL;
}

/**
 * str_rev - Reverse a string in-place
 *
 * @buffer: The string to reverse.
 * @i: The index up to which the string should be reversed.
 */

void	str_rev(char *buffer, int i)
{
	int j, k;
	char tmp;

	j = 0;
	k = i - 1;
	while (j < k)
	{
		tmp = buffer[j];
		buffer[j] = buffer[k];
		buffer[k] = tmp;
		j++;
		k--;
	}
}

/**
 * _itoa - Convert an integer to a string
 *
 * @n: The integer to convert.
 *
 * Return: A dynamically allocated string representing the integer.
 */

char	*_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	str_rev(buffer, i);
	return (_strdup(buffer));
}

/**
 * _perror - Print a custom error message for command not found
 *
 * @av: The program name.
 * @cmd: The command that was not found.
 * @cntr: The line number where the error occurred.
 */

void	_perror(char *av, char *cmd, int cntr)
{
	char *counter;

	counter = _itoa(cntr);
	write(STDIN_FILENO, av, _strlen(av));
	write(STDIN_FILENO, ": ", 2);
	write(STDIN_FILENO, counter, _strlen(counter));
	write(STDIN_FILENO, ": ", 2);
	write(STDIN_FILENO, cmd, _strlen(cmd));
	write(STDIN_FILENO, ": not found\n", 13);
	free(counter), counter = NULL;

}
