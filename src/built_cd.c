/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** Function builtins cd
*/

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my.h"
#include "myinc.h"
#include "struct.h"

int my_cd_reverse(list_t *list, char *oldpwd)
{
	int i = search_str(list->cpy_env, "OLDPWD=");
	int j = 0;
	char *pwd = NULL;

	if (i == 0) {
		my_printf(": No such file or directory.\n");
		return (1);
	}
	for (; list->cpy_env[i][j] != '='; ++j);
	pwd = my_strdup(list->cpy_env[i] + j + 1);
	chdir(pwd);
	if (pwd == NULL)
		return (1);
	if (modif_env(list, pwd, oldpwd) == -1)
		return (1);
	free(pwd);
	return (0);
}

int builtins_cd_bis(list_t *list, char *oldpwd, char *str)
{
	if (my_strcmp(str, "-") == 0) {
		if (my_cd_reverse(list, oldpwd) == 1)
			return (1);
	} else if (access(str, F_OK) == 0) {
			my_printf("%s: Not a directory.\n", str);
			return (1);
	} else {
		my_printf("%s: No such file or directory.\n", str);
		return (1);
	}
	return (0);
}

int my_cd_home(list_t *list, char *oldpwd)
{
	int i = search_str(list->cpy_env, "HOME=");
	int j = 0;
	char *pwd = NULL;

	if (i == 0) {
		my_printf("cd: No home directory.\n");
		return (1);
	}
	for(; list->cpy_env[i][j] != '='; ++j);
	pwd = my_strdup(list->cpy_env[i] + j + 1);
	chdir(pwd);
	if (pwd == NULL)
		return (1);
	if (modif_env(list, pwd, oldpwd) == -1)
		return (1);
	free(pwd);
	return (0);
}

int error_cd(list_t *list, char **tab, char *oldpwd, char *pwd)
{
	int error = 0;

	if (my_strlen_str(tab) > 2) {
		my_putstr("cd: Too many arguments.\n");
		return (0);
	}
	if (my_strlen_str(tab) == 2 && chdir(tab[1]) == 0) {
		getcwd(pwd, PATH_MAX);
		if (modif_env(list, pwd, oldpwd) == -1)
			return (1);
	} else if (my_strlen_str(tab) == 2 && chdir(tab[1]) != 0) {
		error = builtins_cd_bis(list, oldpwd, tab[1]);
		return (error);
	}
	return (0);
}

int builtins_cd(list_t *list, char **tab)
{
	int error = 0;
	char oldpwd[PATH_MAX + 1] = "";
	char pwd[PATH_MAX + 1] = "";

	getcwd(oldpwd, PATH_MAX);
	if (my_strlen_str(tab) == 1 ||
		(my_strlen_str(tab) == 2 && my_strcmp(tab[1], "~") == 0)) {
		error = my_cd_home(list, oldpwd);
		return (error);
	}
	if (error_cd(list, tab, oldpwd, pwd) != 0)
		return (1); 
	return(0);
}