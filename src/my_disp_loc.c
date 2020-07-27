/*
** EPITECH PROJECT, 2017
** Projet MINISHELL1
** File description:
** Function for disp prompt
*/

#include <stdlib.h>
#include "my.h"
#include "myinc.h"

void cut_loc(char *env)
{
	int i = my_strlen(env);

	for (; env[i] != '='; --i);
	my_putstr(env + i + 1);
}

void disp_end_loc(char *env)
{
	int i = my_strlen(env) - 1;

	for (; env[i] != '/'; --i);
	my_putstr(env + i + 1);
}

void disp_loc(list_t *list)
{
	my_putchar('[');
	for (int i = 0; list->cpy_env[i]; ++i) {
		if (my_strncmp("LOGNAME", list->cpy_env[i], my_strlen("LOGNAME")) == 0)
			cut_loc(list->cpy_env[i]);
	}
	my_putstr("@localhost ");
	for (int j = 0; list->cpy_env[j]; ++j) {
		if (my_strncmp("PWD", list->cpy_env[j], my_strlen("PWD")) == 0)
			disp_end_loc(list->cpy_env[j]);
	}
	my_putstr("]$ ");
}