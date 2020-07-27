/*
** EPITECH PROJECT, 2017
** MY_PUTCHAR.C (FOR LIB)
** File description:
** Function for dis a character
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}