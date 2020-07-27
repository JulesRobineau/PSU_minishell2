/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** Function main
*/

#include <unistd.h>
#include "my.h"
#include "myinc.h"

int main(int ac, char **av __attribute__((unused)), char **envp)
{
	list_t list;

	list.prompt = isatty(STDIN_FILENO);
	receive_signal();
	if (ac != 1) {
		my_putstr("Error !");
		return (84);
	}
	if (save_env(envp, &list) == 84)
		return (84);
	if (my_minishell(&list) == 84)
		return (84);
	return (list.exit_status);
}