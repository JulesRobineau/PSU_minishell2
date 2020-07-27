/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** function for treat str with fork
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "myinc.h"
#include "struct.h"

int my_check_str(char *str)
{
	int i = 0;

	for (; str[i]; ++i) {
		if (str[i] == '/')
			return (1);
	}
	return (0);
}

int my_access_path(list_t *list, char *str)
{
	pid_t son;
	int status = 0;

	list->save_error = 0;
	if (access(str, X_OK) == 0) {
		son = fork();
		if (son == 0) {
			execve(str, list->arg, list->cpy_env);
			exit(1);
		} else
			waitpid(son, &status, 0);
		if (status != 0) {
			my_putstr(strsignal(status));
			my_putchar('\n');
			list->save_error = status % 256;
		}
		return (1);
	}
	return (0);
}

int other_builtins(list_t *list)
{
	char *str = NULL;

	for (int i = 0; list->check_path == 1 && list->cpy_path[i]; ++i) {
		if (my_check_str(list->arg[0]) == 0) {
			str = my_strcat(list->cpy_path[i], "/");
			str = my_strcat(str, list->arg[0]);
			if (my_access_path(list, str) != 0)
				return (0);
			free(str);
		} else {
			if (my_access_path(list, list->arg[0]) != 0)
				return (0);
			break;
		}
	}
	if (list->check_path == 0 && my_access_path(list, list->arg[0]) != 0)
		return (0);
	my_printf("%s: Command not found.\n", list->arg[0]);
	return (1);
}