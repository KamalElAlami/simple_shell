#include "shell.h"

/**
 * bfree - release a pointer and set the address to NULL
 * @ptr: address of the free pointer.
 *
 * Return: If released, 1; if not, 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}