##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## projet MINISHELL2
##

NAME	=	mysh

SRC		=	src/main.c\
			src/my_minishell.c\
			src/my_disp_loc.c\
			src/save_env.c\
			src/treat_str.c\
			src/check_builtins.c\
			src/built_setenv.c\
			src/built_unsetenv.c\
			src/built_cd.c\
			src/built_cd_bis.c\
			src/signal.c\
			src/other_builtins.c\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I include/ -Wall -Wextra

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o  $(NAME) $(OBJ) $(CFLAGS) -L./lib/my -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
