/*
** EPITECH PROJECT, 2018
** MY_PUTTAB.C (FOR LIB)
** File description:
** Function disp a char**
*/

#include "my.h"

void my_puttab(char **tab)
{
	for (int i = 0; tab[i]; ++i) {
		my_putstr(tab[i]);
		my_putchar('\n');
	}
}