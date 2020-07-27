/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** Function builtins setenv
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "myinc.h"
#include "struct.h"

char **search_env(list_t *list, char *str)
{
	int i = 0;
	int j = 0;
	char **cpy = malloc(sizeof(char *) * (list->nbr_lenv + 1));

	if (cpy == NULL)
		return (NULL);
	for (; list->cpy_env[i]; ++i) {
		if (my_strncmp(str, list->cpy_env[i], my_strlen(str)) == 0
			&& list->cpy_env[i][my_strlen(str)] == '=') {
			free(list->cpy_env[i]);
			list->nbr_lenv--;
		} else {
			cpy[j] = my_strdup(list->cpy_env[i]);
			if (cpy[j] == NULL)
				return (NULL);
			free(list->cpy_env[i]);
			j++;
		}
	}
	cpy[j] = NULL;
	free(list->cpy_env);
	return (cpy);
}

void new_env(list_t *list, char **tab)
{
	int i = 1;

	for (; tab[i]; i++) {
		list->cpy_env = search_env(list, tab[i]);
	}
}

int builtins_unsetenv(list_t *list, char **tab)
{
	int i = 0;

	for (; tab[i]; ++i);
	if (i == 1) {
		my_putstr("unsetenv: Too few arguments.\n");
		return (1);
	}
	new_env(list, tab);
	return (0);
}