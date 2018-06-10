/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void	my_pong(char **av)
{
	int n = atof(av[7]);
	float x2 = atof(av[4]) - atof(av[1]);
	float y2 = atof(av[5]) - atof(av[2]);
	float z2 = atof(av[6]) - atof(av[3]);
	float nx = atof(av[4]) + x2 * n;
	float ny = atof(av[5]) + y2 * n;
	float nz = atof(av[6]) + z2 * n;
	float angle = (180 * acos(z2 / (sqrt((x2*x2) + (y2 * y2) + (z2 * z2)))) / M_PI) - 90;

	(angle <= 0) ? angle *= -1 : angle;
	printf("The speed vector coordinates are :\n(%.2f;%.2f;%.2f)\n", x2, y2, z2);
	printf("At time t+%d, ball coordinates will be :\n(%.2f;%.2f;%.2f)\n", n, nx, ny, nz);
	if ((-(atof(av[6]))) / z2 >= 0 && nx != 0) {
		if (angle == 0)
			puts("The incidence angle is :\n0.00 degrees");
		else
			printf("The incidence angle is :\n%.2f degrees\n", angle);
	} else {
		if (atof(av[3]) == 0 && atof(av[6]) == 0)
			puts("The incidence angle is :\n0.00 degrees");
		else
			puts("The ball won't reach the bat.");
	}
}

void	check_av(char **av)
{
	int	i = 0;
	
	for (i = 1 ; av[i] ; i++) {
		if ((my_str_isnum(av[i])) != 0) {
			puts("Please enter only numbers");
			exit(84);
		}
	}
	for (i = 0; av[7][i] ; i++)
		if (av[7][i] == '.') {
			puts("n should not be a float");
			exit(84);
		}
	if (atoi(av[7]) < 0) {
		puts("n should be positif");
		exit(84);
	}
}

int	main(int ac, char **av)
{
	if (ac != 8) {
		puts("Bad usage : Enter 7 argument !");
		return (84);
	}
	check_av(av);
	my_pong(av);
	return (0);
}
