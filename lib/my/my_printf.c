/*
** EPITECH PROJECT, 2017
** MY_PRINTF (FOR LIB)
** File description:
** Function printf for disp a string, a character and a int
*/

#include <stdarg.h>
#include "my.h"

int special_cases(char c, va_list ap)
{
	switch (c) {
	case '%':
		my_putchar('%');
		break;
	case 'S':
		my_putchar('\0');
		my_put_base("01234567", va_arg(ap, int));
		break;
	}
	return (0);
}

int various_bases(char c, va_list ap)
{
	switch (c) {
	case 'b':
		my_put_base("01", va_arg(ap, int));
		break;
	case 'o':
		my_put_base("01234567", va_arg(ap, int));
		break;
	case 'u':
		my_put_base("0123456789", va_arg(ap, unsigned int));
		break;
	case 'x':
		my_put_base("0123456789abcdef", va_arg(ap, long));
		break;
	case 'X':
		my_put_base("0123456789ABCDEF", va_arg(ap, long));
		break;
	default :
		special_cases(c, ap);
	}
	return (0);
}

int basic_cases(char c, va_list ap)
{
	switch (c) {
	case 'd':
		my_put_nbr(va_arg(ap, int));
		break;
	case 'p':
		my_putstr("0x");
		my_put_base("0123456789abcdef", va_arg(ap, long));
		break;
	case 'i':
		my_put_nbr(va_arg(ap, int));
		break;
	case 's':
		my_putstr(va_arg(ap, char*));
		break;
	case 'c':
		my_putchar(va_arg(ap, int));
		break;
	default :
		various_bases(c, ap);
	}
	return (0);
}

int my_printf(char *str, ...)
{
	va_list ap;
	va_start(ap, str);

	for (int i = 0; str[i]; ++i) {
		if (str[i] == '%') {
			basic_cases(str[i + 1], ap);
			++i;
		} else
			my_putchar(str[i]);
	}
	va_end(ap);
	return (0);
}