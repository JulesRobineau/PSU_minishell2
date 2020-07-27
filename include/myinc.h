/*
** EPITECH PROJECT, 2017
** myinc.h
** File description:
** projet MINISHELL2
*/

#ifndef MYINC_H
#define MYINC_H

#include "struct.h"

int main(int ac, char **av __attribute__((unused)), char **envp);
int my_minishell(list_t *);
void disp_loc(list_t *);
int save_env(char **, list_t *);
int treat_str(list_t *);
void receive_signal(void);
int other_builtins(list_t *);
int modif_env(list_t *, char *, char *);

int my_env(list_t *, char **);
int builtins_setenv(list_t *, char **);
int builtins_unsetenv(list_t *, char **);
int builtins_cd(list_t *, char **);
int my_exit(list_t *, char **);

typedef struct builtin {
	const char *name;
	int (*function)(list_t *list, char **tab);
}builtin_t;

static const builtin_t BUILTIN[] = {
	{"exit", my_exit},
	{"env", my_env},
	{"setenv", builtins_setenv},
	{"unsetenv", builtins_unsetenv},
	{"cd", builtins_cd},
};

#endif
