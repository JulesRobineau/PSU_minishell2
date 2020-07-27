/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** function for treat str
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "my.h"
#include "myinc.h"
#include "struct.h"

void my_free_arg(list_t *list)
{
	for (int i = 0; list->arg[i]; ++i)
		free(list->arg[i]);
	free(list->arg);
}

int search_arg(list_t *list, char *str)
{
	list->arg = mystr_toword_array(str, ' ');
	for (int i = 0; i < 5; ++i) {
		if (my_strcmp(BUILTIN[i].name, list->arg[0]) == 0) {
			list->exit_status = BUILTIN[i].function(list, list->arg);
			my_free_arg(list);
			return (0);
		}
	}
	list->exit_status = other_builtins(list);
	if (list->save_error != 0)
		list->exit_status = list->save_error;
	my_free_arg(list);
	return (0);
}

int treat_str(list_t *list)
{
	char *str = "";

	str = get_next_line(STDIN_FILENO);
	if (str == NULL)
		return (-1);
	if (my_strlen(str) > 0) {
		search_arg(list, str);
	}
	free(str);
	return (0);
}