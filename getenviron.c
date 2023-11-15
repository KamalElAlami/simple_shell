#include "main.h"

/**
 * _getenviron - Get environment variable value
 *
 * @cmd: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */


char	*_getenviron(char *cmd)
{
	char *strt, *val, *targ, *temp;
	int i;

	i = 0;
	while (environ[i])
	{
		temp = _strdup(environ[i]);
		strt = strtok(temp, "=");
		if (_strcmp(strt, cmd) == 0)
		{
			val = strtok(NULL, "\n");
			targ = _strdup(val);
			free(temp);
			return (targ);
		}
		free(temp), temp = NULL;
		i++;
		}
	return (NULL);
}
