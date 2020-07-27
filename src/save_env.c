/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "myinc.h"

int nbr_env(char **env)
{
	int i = 0;

	for (; env[i]; ++i);
	return (i);
}

void save_path(list_t *list)
{
	int i = 0;
	char *path = NULL;

	list->check_path = 0;
	for (; list->cpy_env[i]; ++i) {
		if (list->cpy_env[i][my_strlen("PATH")] == '='
			&& my_strncmp("PATH", list->cpy_env[i], my_strlen("PATH")) == 0)
			path = my_strdup(list->cpy_env[i]);
	}
	if (path != NULL) {
		list->cpy_path = mystr_toword_array(path + my_strlen("PATH="), ':');
		free(path);
		list->check_path = 1;
	}
}

int save_env(char **env, list_t *list)
{
	int i = 0;
	int cpt_env = nbr_env(env);

	list->check_env = 0;
	list->cpy_env = malloc(sizeof(char *) * (cpt_env + 1));
	if (list->cpy_env == NULL)
		return (84);
	for (; env[i]; ++i) {
		list->cpy_env[i] = my_strdup(env[i]);
		if (list->cpy_env[i] == NULL)
			return (84);
	}
	if (i == 0)
		list->check_env = 1;
	list->cpy_env[i] = NULL;
	list->nbr_lenv = i;
	save_path(list);
	return (0);
}