#include "shell.h"

/**
 *_eputs - outputs the input string.
 * @str: the text to be typed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes "c" to the standard error
 * @c: The text to be printed
 *
 * Return: success 1.
 * Errno is set appropriately and -1 is returned in the event of an error.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - sends the character c to the specified fd.
 * @c: The text to be printed
 * @fd: To write to, use the filedescriptor
 *
 * Return: success 1.
 * Errno is set appropriately and -1 is returned in the event of an error.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - outputs the input string.
 * @str: the text to be typed
 * @fd: The field descriptor to correspond with
 *
 * Return: how many characters are entered
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}