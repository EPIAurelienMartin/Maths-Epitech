/*
** EPITECH PROJECT, 2017
** str
** File description:
** isnum
*/

#include "architecte.h"

int	my_str_isnum(char *str)
{
	int	i = 0;

	if (str[0] == '\0')
		return (0);
	if (str[i] == '-')
		i += 1;
	while (str[i]) {
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	return (0);
}
