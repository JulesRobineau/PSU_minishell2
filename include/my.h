/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** For lib: prototypes all funtions .c
*/

#ifndef MY_H
#define MY_H

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
int search_str(char **, char *);
char *my_revstr(char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strcat(char *, char const *);
char *my_strdup(char const *);
int my_printf(char *, ...);
int my_put_base(char *, long );
char *my_realloc(char *, int);
char *get_next_line(int);
char **mystr_toword_array(char *, char);
char *my_cleanup_str(char *, char);
void my_free_tab(char **);
void my_puttab(char **);
int my_strlen_str(char **);
int my_str_isalpha(char const *);
int my_getnbr(char *);
int my_str_isnum(char const *);

#endif
