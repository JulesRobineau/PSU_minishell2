/*
** EPITECH PROJECT, 2017
** MY_STR_ISNUM.C
** File description:
** Function for know if a string countain that number
*/

int my_str_isnum(char const *str)
{
	int flag;

	flag = 1;
	if (str[0] == '\0')
		flag = 1;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			flag = 0;
	}
	return (flag);
}