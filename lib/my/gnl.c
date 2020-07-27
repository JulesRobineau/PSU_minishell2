/*
** EPITECH PROJECT, 2018
** MY_GET_NEXT_LINE.C (FOR LIB)
** File description:
** Function for exit a string line by line
*/

#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

int check_buff(char *buff, char **dest, char *save)
{
	int end_line = 0;

	for (int i = 0; buff[i] != '\0'; ++i) {
		if (buff[i] == '\n') {
			end_line = 1; 
			buff[i] = '\0';
			my_strcpy(save, buff + i + 1);
			break;
		}
	}
	*dest = my_realloc(*dest, my_strlen(*dest) + READ_SIZE);
	*dest = my_strcat(*dest, buff);
	return (end_line);
}

char *get_next_line(int fd)
{
	char buff[READ_SIZE + 1] = "";
	static char save[READ_SIZE + 1] = "";
	char *des = NULL;

	if (fd == -1)
		return (des);
	if (my_strlen(save) > 0) {
		my_strcpy(buff, save);
		save[0] = '\0';
	}
	else if (read(fd, buff, READ_SIZE) <= 0)
		return (des);
	while (check_buff(buff, &des, save) != 1) {
		for (int i = 0; i < READ_SIZE; ++i)
			buff[i] = '\0';
		if (read(fd, buff, READ_SIZE) <= 0)
			return (des);
	}
	return (des);
}