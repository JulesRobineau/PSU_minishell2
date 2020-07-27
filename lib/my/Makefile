##
## EPITECH PROJECT, 2017
## For my lib
## File description:
## Makefile (lib)
##

CC	=	gcc

AR	=	ar rc

CFLAGS	=	-Wall -Wextra -g3

NAME	=	libmy.a

SRCS	=	my_printf.c\
		my_put_base.c\
		my_putchar.c\
		my_put_nbr.c\
		my_putstr.c\
		my_strncpy.c\
		my_realloc.c\
		my_revstr.c\
		my_strcat.c\
		my_strncat.c\
		my_strcmp.c\
		my_strcpy.c\
		my_strlen.c\
		my_search_str.c\
		my_strncmp.c\
		my_strdup.c\
		my_puttab.c\
		gnl.c\
		mystr_toword_array.c\
		my_cleanup_str.c\
		my_free_tab.c\
		my_strlen_str.c\
		my_str_isalpha.c\
		my_getnbr.c\
		my_str_isnum.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		cp my.h ../../include
		cp get_next_line.h ../../include
		$(AR) $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)
fclean:	clean
		rm -f $(NAME)
		rm -f *.a

re:	fclean all

.PHONY: all clean fclean re $(NAME)
