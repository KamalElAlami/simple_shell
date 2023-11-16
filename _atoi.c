#include "shell.h"

/**
 * interactive - if the shell is in interactive mode, returns true.
 * @info: address of struct
 *
 * Return: If in interactive mode, 1; if not, 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - determines whether a character is a delimeter
 * @c: the char to examine
 * @delim: the string delimeter
 * Return: 0 if false, 1 if true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - looks for characters in the alphabet
 *@c: The input character
 *Return: In case c is alphabetic, 1; if not, 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - creates an integer from a string
 *@s: the text that has to be changed
 *Return: 0 If there are no numbers in the string the converted number
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}