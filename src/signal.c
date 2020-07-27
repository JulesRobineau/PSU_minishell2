/*
** EPITECH PROJECT, 2018
** Projet MINISHELL1
** File description:
** function signal
*/

#include <signal.h>
#include "my.h"

void treat_signal(int sig)
{
	if (sig == 2)
		my_putchar('\n');
}

void receive_signal(void)
{
	signal(SIGINT, &treat_signal);
}