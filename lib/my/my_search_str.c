/*
** EPITECH PROJECT, 2018
** MY_SEARCH_STR.C (FOR LIB)
** File description:
** Function for search a str* on char**
*/

#include "my.h"

int search_str(char **tab, char *str)
{
	for (int i = 0; tab[i]; ++i) {
		if (my_strncmp(tab[i], str, my_strlen(str)) == 0)
			return (i);
	}
	return (0);
}