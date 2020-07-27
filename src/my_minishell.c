/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** Function for gestion of minishell
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "myinc.h"

void free_env(list_t *list)
{
	for (int i = 0; list->cpy_env[i]; ++i)
		free(list->cpy_env[i]);
	free(list->cpy_env);
}

int my_minishell(list_t *list)
{
	int flag = 0;

	list->stop = 1;
	while (list->stop == 1) {
		if (list->prompt)
			disp_loc(list);
		flag = treat_str(list);
		if (flag == 84)
			return (84);
		if (flag == -1) {
			my_putstr("exit\n");
			list->stop = 0;
		}
	}
	free_env(list);
	return (0);
}