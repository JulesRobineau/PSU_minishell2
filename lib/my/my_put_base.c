/*
** EPITECH PROJECT, 2017
** MY_PUT_BASE.C (FOR LIB)
** File description:
** Function for disp anything string with base
*/

#include "my.h"

int my_put_base(char *base, long nb)
{
	int length = my_strlen(base);

	if (nb >= length)
		my_put_base(base, nb / length);
	my_putchar(base[nb % length]);
	return (0);
}