/*
** EPITECH PROJECT, 2018
** MY_CLEANUP_STR.C (FOR LIB)
** File description:
** Function for clean a str
*/

#include <stdio.h>
#include <stdlib.h>

char *precleanup_str(char *str)
{
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}

int check_carac(char carac)
{
	if (carac != 32 && carac != '\t' && carac != '\0')
		return (1);
	return (0);
}

int cpt_char_str(char *str, char carac)
{
	int cpt = 0;
	int i = 0;

	for (; str[i] == ' ' || str[i]  == '\t'; ++i);
	for (; str[i]; ++i) {
		if (str[i] == carac && check_carac(str[i + 1]) == 1)
			cpt++;
		else if (str[i] != carac && check_carac(str[i]) == 1)
			cpt++;
	}
	return (cpt);
}

char *my_cleanup_str(char *str, char carac)
{
	int i = 0;
	char *dest;

	precleanup_str(str);
	dest = malloc(sizeof(char) * (cpt_char_str(str, carac) + 1));
	if (dest == NULL)
		return (NULL);
	for (; str[i] == ' ' || str[i] == '\t'; ++i);
	for (int j = 0; str[i]; ++i) {
		if (str[i] == carac && check_carac(str[i + 1]) == 1) {
			dest[j] = str[i];
			j++;
		}
		if (str[i] != carac && check_carac(str[i]) == 1) {
			dest[j] = str[i];
			j++;
		}
	}
	dest[cpt_char_str(str, carac)] = '\0';
	return (dest);
}