/*
** EPITECH PROJECT, 2017
** Projet MINISHELL1
** File description:
** finction structure
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct list {
	int save_error;
	int exit_status;
	int check_env;
	int nbr_lenv;
	int check_path;
	int prompt;
	int stop;
	char **cpy_env;
	char **cpy_path;
	char **arg;
}list_t;

#endif