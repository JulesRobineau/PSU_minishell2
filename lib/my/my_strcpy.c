/*
** EPITECH PROJECT, 2017
** MY_STRCPY.C (FOR LIB)
** File description:
** Function for cpy a string in other
*/

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	for (; src[i]; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}