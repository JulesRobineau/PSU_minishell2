/*
** EPITECH PROJECT, 2017
** MY_STRNCAT.C (FOR LIB)
** File description:
** For lib: function for concatenate two strings with n caractere
*/

#include <stdlib.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int j = 0;
	int cpt = my_strlen(dest) + nb;
	char *save = malloc(sizeof(char) * (cpt + 1));

	if (save == NULL)
		return (NULL);
	i = my_strlen(dest);
	for (; j < nb; ++j)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}