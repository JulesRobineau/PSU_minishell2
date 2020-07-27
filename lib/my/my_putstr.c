/*
** EPITECH PROJECT, 2017
** MY_PUTSTR.C (FOR LIB)
** File description:
** Function for disp character by character one string
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
	return (0);
}