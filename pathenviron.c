#include "main.h"

/**
 * _pathenviron - Find executable file in PATH environment
 *
 * @cmd: The name of the executable file to search for.
 *
 * Return: The full path to the executable file, or NULL if not found.
 */


char *_pathenviron(char *cmd)
{
	char *penv, *fcmd, *direc;
	int i;
	struct stat stt;

	i = 0;
	penv = _getenviron("PATH");
	direc = strtok(penv, ":");
	while (direc)
	{
		fcmd = malloc(_strlen(direc) + _strlen(cmd) + 2);
		if (fcmd)
		{
			_strcpy(fcmd, direc);
			_strcat(fcmd, "/");
			_strcat(fcmd, cmd);
			if (stat(fcmd, &stt) == 0)
			{
				free(penv);
				return (fcmd);
			}
			free(fcmd), fcmd = NULL;
			direc = strtok(NULL, ":");
			}
		}
	if (!penv)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &stt) == 0)
				return (free(penv), _strdup(cmd));
			else
				return (NULL);
		}
		i++;
	}
	free(penv);
	return (NULL);
}
