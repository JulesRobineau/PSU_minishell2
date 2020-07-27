/*
** EPITECH PROJECT, 2017
** MY_GETNBR.C (FOR LIB)
** File description:
** Function for transformed a int in char* 
*/

int my_getnbr(char *str)
{
	int nb = 0;
	int sign = 1;
	int i = 0;

	while ((str[i] == '-' || str[i] == '+')
	|| (str[i] < '0' && str[i] > '9')) {
		str++;
		if (*str == '-')
			sign = sign * -1;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ') {
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	nb = nb * sign;
	return (nb);
}