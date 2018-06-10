/*
** EPITECH PROJECT, 2018
** 107
** File description:
** ...
*/

#include "my.h"

double	my_res(char *str, double nb)
{
	int	a = my_strlen(str) - 1;
	double	ret = 0;

	for (a = a; (a >= 0); a -= 2) {
		for (a = a; (a >= 0 && str[a] != '*'); a--);
		a++;
		ret = ret * nb + (float)(str[a] - 48);
	}
	return (ret);
	
}

void	my_panel(void)
{
	my_printf("USAGE\n\t./107transfer [num den]*\n\n");
	my_printf("DESCRIPTION\n\tnum\tpolynomial numerator defined by its ");
	my_printf("coeficients\n\tden\tpolynomial denominator defined by its coeficients\n");
}

int	main(int ac, char **av)
{
	int	a = 1;
	int	b = 0;
	double	two = 1;
	double	one = 0.00000;
	double add = 0.00100;


	if (ac < 2 || ac % 2 == 0)
		return (84);
	if (my_strcmp(av[1], "-h") == 0) {
		my_panel();
		return (0);
	}
	for (a = 1; (a < ac); a++) {
		for (b = 0; (av[a][b]); b++) {
			if (av[a][b] != '*' && (av[a][b] < '0' || av[a][b] > '9') && av[a][b] != '-')
				return (84);
		}
	}
	a = 1;
	for (two = 1; (one < 1.00100); one += add) {
		two = 1;
		for (a = 1; (a < ac); a += 2)
			two *= my_res(av[a], one) / my_res(av[a + 1], one);
		printf("%g -> %.5f\n", one, two);
	}
	return (0);
}
