/*
** EPITECH PROJECT, 2018
** MY_STR_TOXORD_ARRAY.C(FOR LIB)
** File description:
** Function for separate whit space a char* on char**
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int cpt_space(char *str, char carac)
{
	int i = 0;
	int cpt = 0;

	for (; str[i]; i++) {
		if (str[i] == carac && str[i + 1] != '\0')
			cpt++;
	}
	cpt++;
	return (cpt);
}

char *my_separate_str(char *str, int prev, int i)
{
	char *dest = malloc(sizeof(char) * (i - prev + 1));

	if (str == NULL)
		return (NULL);
	dest[i - prev] = '\0';
	for (int tmp = 0; tmp < i - prev; tmp++)
		dest[tmp] = str[prev + tmp];
	return (dest);
}

char **mystr_toword_array(char *str, char carac)
{
	int i = 0;
	int j = 0;
	int prev = 0;
	char **tab;

	str = my_cleanup_str(str, carac);
	tab = malloc(sizeof(char *) * (cpt_space(str, carac) + 1));
	if (tab == NULL || str == NULL)
		return (NULL);
	tab[cpt_space(str, carac)] = NULL;
	for (; i <= my_strlen(str); i++) {
		if ((str[i] == carac && str[i] != '\0') || str[i] == '\0') {
			tab[j] = my_separate_str(str, prev, i);
			if (tab[j++] == NULL)
				return (NULL);
			prev = i + 1;
		}
	}
	return (tab);
}