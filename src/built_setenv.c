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

char *change_env(char *arg1, char *arg2)
{
	int i = 0;
	int j = my_strlen(arg2);
	char *dest = NULL;

	for (; arg1[i] != '='; ++i);
	i++;
	dest = malloc(sizeof(char) * (i + j + 1));
	if (dest == NULL)
		return (NULL);
	my_strncpy(dest, arg1, i);
	if (arg2 != NULL)
		my_strcpy(dest + i, arg2);
	else
		my_strcpy(dest + i, "\0");
	return (dest);
}

int exist_setenv(list_t *list, char **tab)
{
	for (int i = 0; list->cpy_env[i]; ++i) {
		if (my_strncmp(list->cpy_env[i], tab[1], my_strlen(tab[1])) == 0
			&& list->cpy_env[i][my_strlen(tab[1])] == '=') {
			list->cpy_env[i] = change_env(list->cpy_env[i], tab[2]);
			return (1);
		}
	}
	return (0);
}

char **setenv_no_exist(list_t *list, char **tab, int nbr_arg)
{
	int i = 0;
	int cpt = my_strlen(tab[1]) + 1 + my_strlen(tab[2]);
	char **cpy;

	cpy = malloc(sizeof(char *) * (list->nbr_lenv + 2));
	if (cpy == NULL)
		return (NULL);
	for (; list->cpy_env[i]; ++i)
		cpy[i] = list->cpy_env[i];
	cpy[i] = malloc(sizeof(char) * (cpt + 1));
	if (cpy[i] == NULL)
		return (NULL);
	my_strcpy(cpy[i], tab[1]);
	cpy[i] = my_strcat(cpy[i], "=");
	if (nbr_arg > 2)
		cpy[i] = my_strcat(cpy[i], tab[2]);
	cpy[i + 1] = NULL;
	list->nbr_lenv++;
	return (cpy);
}

int builtins_setenv(list_t *list, char **tab)
{
	if (my_strlen_str(tab) > 3) {
		my_putstr("setenv: Too many arguments.\n");
		return (1);
	}
	if (my_strlen_str(tab) == 1) {
		my_puttab(list->cpy_env);
		return (0);
	}
	if (!((tab[1][0] >= 'A' && tab[1][0] <= 'Z')
		|| (tab[1][0] >= 'a' && tab[1][0] <= 'z'))) {
		my_putstr("setenv: Variable name must begin with a letter.\n");
		return (1);
	}
	if (my_str_isalpha(tab[1]) == 0) {
		my_putstr("setenv: Variable name must ");
		my_putstr("contain alphanumeric characters.\n");
		return (1);
	}
	if (exist_setenv(list, tab) == 1)
		return (0);
	list->cpy_env = setenv_no_exist(list, tab, my_strlen_str(tab));
	return (0);
}