/*
** EPITECH PROJECT, 2017
** MY_PUT_NBR.C (FOR LIB)
** File description:
** Function for disp a int
*/

#include "my.h"

int my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		my_put_nbr(nb / 10);
	my_putchar((nb % 10) + '0');
	return (0);
}