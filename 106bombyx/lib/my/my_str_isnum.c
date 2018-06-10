/*
** EPITECH PROJECT, 2017
** is_num
** File description:
** is_num
*/

int	my_str_isnum(char const *str)
{
	int	a = 0;

	if (str[a] == '\0' || str[a] == '.')
		return (1);
	while (str[a]) {
		if ((str[a] >= '0' && str[a] <= '9') || str[a] == '.')
			a++;
		else
			return (0);
	}
	return (1);
}
