/*
** EPITECH PROJECT, 2018
** bombyx
** File description:
** ...
*/

#include "my.h"

void	my_aff_h(void);

int	calc2(double x, int min, int max)
{
	int	i = 1;
	double	k = 1;

	while (k <= 4) {
		i = 2;
		while (i < min - 1) {
			x = k * x * ((1000 - x) / 1000);
			i++;
		}
		while (i < max)	{
			x = k * x * ((1000 - x) / 1000);
			printf("%.2f %.2f\n", k, x);
			i++;
		}
		k = k + 0.01;
	}
	return (0);
}

int	calc(int n, double k)
{
	int	i = 1;
	double	x1 = n;
	double	x2 = k * x1 * ((1000 - x1) / 1000);

	printf("%d %.2f\n", i, x1);
	i++;
	while (i <= 100) {
		x1 = x2;
		x2 = k * x1 * ((1000 - x1) / 1000);
		printf("%d %.2f\n", i, x1);
		i++;
	}
	return (0);
}

int	first_option_operator(char *str1, char *str2)
{
	int	n = 0;
	double	k = 0;

	if (my_str_isnum(str1) != 0)
		n = atoi(str1);
	else
		return (1);
	if (my_str_isnum(str2) != 0)
		k = strtod(str2, NULL);
	else
		return (1);
	if (k >= 1 && k <= 4)
		calc(n, k);
	else
		return (1);
	return (0);
}

int	second_option_operator(char *str1, char *str2, char *str3)
{
	int	min = 0;
	int	max = 0;
	double	x1 = 0;

	if ((my_str_isnum(str1) != 0) && (my_str_isnum(str2) != 0)) {
		x1 = atoi(str1);
		min = atoi(str2);
	} else
		return (1);
	if (my_str_isnum(str3) != 0)
		max = atoi(str3);
	else
		return (1);
	if (min <= max && x1 < min)
		calc2(x1, min, max);
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2 && my_strcmp(av[1], "-h") == 0)
		my_aff_h();
	else if (ac == 3) {
		if (first_option_operator(av[1], av[2]) != 0)
			return (84);
	}
	else if (ac == 4) {
		if (second_option_operator(av[1], av[2], av[3]) != 0)
			return (84);
	} else
		return (84);
	return (0);
}
