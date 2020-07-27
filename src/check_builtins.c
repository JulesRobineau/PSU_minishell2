/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** Function check builtins
*/

#include <unistd.h>
#include "my.h"
#include "myinc.h"
#include "struct.h"

int my_env(list_t *list, char **tab __attribute__((unused)))
{
	int nbr_l = my_strlen("OLDPWD=");
	if (list->check_env == 0)
		my_puttab(list->cpy_env);
	else 
		for (int i = 0; list->cpy_env[i]; ++i) {
			if (my_strncmp(list->cpy_env[i], "OLDPWD=", nbr_l) != 0) {
				my_putstr(list->cpy_env[i]);
				my_putchar('\n');
			}
		}
	return (0);
}

int my_exit(list_t *list, char **tab)
{
	if (my_strlen_str(tab) == 1) {
		my_putstr("exit\n");
		list->stop = 0;
		return (0);
	}
	if (my_strlen_str(tab) == 2 && my_str_isnum(tab[1]) == 1) {
		my_putstr("exit\n");
		list->stop = 0;
		return (my_getnbr(tab[1]));
	} else {
		my_putstr("exit: Expression Syntax.\n");
		return (1);
	}
	return (0);
}