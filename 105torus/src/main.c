/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "torus.h"

void	print_bisect(t_tor *tor, int av7)
{
	double	x;
	double	c1;
	double	c2;
	double	n = 0;
	double	n1 = 1;

	for (int a = 0; a < 250; a++) {
		if (round(n * pow(10, av7) + 1) >= round(n1 * pow(10, av7)))
			exit(0);
		x = (n + n1) / 2;
		if (a + 1 <= 6)
			printf("x = %.*f\n", a + 1, x);
		else
			printf("x = %.6f\n", x);
		c1 = (tor->a4 * pow(x, 4)) + (tor->a3 * pow(x, 3)) + (tor->a2 * pow(x, 2)) + (tor->a1 * x) + tor->a0;
		c2 = (tor->a4 * pow(n, 4)) + (tor->a3 * pow(n, 3)) + (tor->a2 * pow(n, 2)) + (tor->a1 * n) + tor->a0;
		if (c2 * c1 < 0)
			n1 = x;
		else
			n = x;
	}
}

void	print_newton(t_tor *tor, int av7)
{
	double	n = 0.5;
	double	x;
	double	n1;
	double	n2;

	printf("x = %.1f\n", n);
	for (int a = 0; a < 250; a++) {
		n1 = (tor->a4 * pow(n, 4)) + (tor->a3 * pow(n, 3)) + (tor->a2 * pow(n, 2)) + (tor->a1 * n) + tor->a0;
		n2 = (4 * (tor->a4 * pow(n, 3))) + (3 * (tor->a3 * pow(n, 2))) + (2 * tor->a2 * n) + tor->a1;
		if (n2 == 0)
			exit(0);
		x = n - (n1 / n2);
		if (round(n * pow(10, av7)) == round(x * pow(10, av7)))
			exit(EXIT_SUCCESS);
		printf("x = %.12f\n", x);
		n = x;
	}
}

void	print_secant(t_tor *tor, int av7)
{
	double	c1 = 0.4;
	double	c2 = 0.8;
	double  n1;
	double  n2;
	double  n = 0.5;

	printf("x = %.1f\n", n);
	for (int a = 0; a < 250; a++) {
		if (round(c1 * pow(10, av7)) == round(c2 * pow(10, av7)))
			exit(0);
		n1 = (tor->a4 * pow(c1, 4)) + (tor->a3 * pow(c1, 3)) + (tor->a2 * pow(c1, 2)) + (tor->a1 * c1) + tor->a0;
		n2 = (tor->a4 * pow(c2, 4)) + (tor->a3 * pow(c2, 3)) + (tor->a2 * pow(c2, 2)) + (tor->a1 * c2) + tor->a0;
		if ((n2 - n1) == 0)
			exit(0);
		n = c2 - ((n2) * (c2 - c1) / (n2 - n1));
		printf("x = %.8f\n", n);
		c1 = c2;
		c2 = n;
	}
}

int	bisect(char **av, t_tor *tor)
{
	tor->a0 = my_getnb(av[2]);
	tor->a1 = my_getnb(av[3]);
	tor->a2 = my_getnb(av[4]);
	tor->a3 = my_getnb(av[5]);
	tor->a4 = my_getnb(av[6]);
	print_bisect(tor, my_getnb(av[7]));
	return (0);
}

int	newton(char **av, t_tor *tor)
{
	tor->a0 = my_getnb(av[2]);
	tor->a1 = my_getnb(av[3]);
	tor->a2 = my_getnb(av[4]);
	tor->a3 = my_getnb(av[5]);
	tor->a4 = my_getnb(av[6]);
	print_newton(tor, my_getnb(av[7]));
	return (0);
}

int	secant(char **av, t_tor *tor)
{
	tor->a0 = my_getnb(av[2]);
	tor->a1 = my_getnb(av[3]);
	tor->a2 = my_getnb(av[4]);
	tor->a3 = my_getnb(av[5]);
	tor->a4 = my_getnb(av[6]);
	print_secant(tor, my_getnb(av[7]));
	return (0);
}

int	torus(char **av)
{
	t_tor	tor;

	if (my_str_isnum(av[2]) == 0)
		return (84);
	if (my_str_isnum(av[3]) == 0)
		return (84);
	if (my_str_isnum(av[4]) == 0)
		return (84);
	if (my_str_isnum(av[5]) == 0)
		return (84);
	if (my_str_isnum(av[6]) == 0)
		return (84);
	if (my_getnb(av[1]) == 1)
		return (bisect(av, &tor));
	if (my_getnb(av[1]) == 2)
		return (newton(av, &tor));
	if (my_getnb(av[1]) == 3)
		return (secant(av, &tor));
	return (84);
}

int	main(int ac, char **av)
{
	if (ac == 8) {
		if ((torus(av)) == 84)
			return (84);
	} else
		return (84);
	return (0);
}
