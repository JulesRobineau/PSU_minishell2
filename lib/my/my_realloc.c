/*
** EPITECH PROJECT, 2018
** MY_REALLOC.C (FOR LIB)
** File description:
** Function who realloc a string with a new file
*/

#include <stdlib.h>
#include "my.h"

char *my_realloc(char *src, int new_size)
{
	char *dest = NULL;

	dest = malloc(sizeof(char) * (new_size + 1));
	if (dest == NULL)
		return (dest);
	for (int i = 0; i < new_size + 1; ++i)
		dest[i] = '\0';
	if (src == NULL)
		return (dest);
	dest = my_strcpy(dest, src);
	free(src);
	return (dest);
}