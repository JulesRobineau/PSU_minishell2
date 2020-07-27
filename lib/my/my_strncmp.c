/*
** EPITECH PROJECT, 2017
** MY_STRNCMP.C (FOR LIB)
** File description:
** For lib: function for compare two strings with n caractere
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	if (n == 0)
		return (0);
	while ((s1[i] != '\0' && i < n) || (s2[i] != '\0' && i < n)) {
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}