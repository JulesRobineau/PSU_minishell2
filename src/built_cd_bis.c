/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** Function builtins cd bis
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "myinc.h"

int modif_pwd(list_t *list, char *pwd)
{
	char *save = "";
	char **save_pwd = NULL;

	save = my_strcat(save, "setenv PWD ");
	if (save == NULL)
		return (-1);
	save = my_strcat(save, pwd);
	if (save == NULL)
		return (-1);
	save_pwd = mystr_toword_array(save, ' ');
	if (save_pwd == NULL)
		return (-1);
	builtins_setenv(list, save_pwd);
	free(save);
	my_free_tab(save_pwd);
	return (0);
}

int modif_env(list_t *list, char *pwd, char *oldpwd)
{
	char *save = "";
	char **save_pwd = NULL;

	save = my_strcat(save, "setenv OLDPWD ");
	if (save == NULL)
		return (-1);
	save = my_strcat(save, oldpwd);
	if (save == NULL)
		return (-1);
	save_pwd = mystr_toword_array(save, ' ');
	if (save_pwd == NULL)
		return (-1);
	builtins_setenv(list, save_pwd);
	free(save);
	my_free_tab(save_pwd);
	if (modif_pwd(list, pwd) == -1)
		return (-1);
	return (0);
}