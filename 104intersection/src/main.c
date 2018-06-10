/*
** EPITECH PROJECT, 2017
** intersection
** File description:
** ...
*/

#include "intersection.h"
#include "my.h"


void	display_point(int nb, struct point_t first, struct point_t second, struct point_t point, struct vec_t vector)
{
	printf("straight line going through the (%.f,%.f,%.f)", point.x, point.y, point.z);
	printf(" point and of direction vector (%.f,%.f,%.f)\n", vector.x, vector.y, vector.z);
	if (nb == 0)
		printf("No intersection point.\n");
	if (nb == 1) {
		printf("1 intersection point :\n");
		printf("(%.3f, %.3f, %.3f)\n", first.x, first.y, first.z);
	}
	else if (nb == 2) {
		printf("2 intersection points :\n");
		printf("(%.3f, %.3f, %.3f)\n", second.x, second.y, second.z);
		printf("(%.3f, %.3f, %.3f)\n", first.x, first.y, first.z);
	}
}

void     sphere(char **av)
{
	struct point_t	point;
	struct vec_t	vector;
	int	radius = my_getnbr(av[8]);
	int	nb = 1;
	double	calc1 = 0;
	double	calc2 = 0;
	double	calc3 = 0;
	double	res1 = 0;
	double	res2 = 0;
	double	delta = 0;
	struct point_t	first;
	struct point_t	second;

	point.x = my_getnbr(av[2]);
	point.y = my_getnbr(av[3]);
	point.z = my_getnbr(av[4]);
	vector.x = my_getnbr(av[5]);
	vector.y = my_getnbr(av[6]);
	vector.z = my_getnbr(av[7]);
	calc1 = (powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
	calc2 = ((2 * vector.x * point.x) + (2 * vector.y * point.y) + (2 * vector.z * point.z));
	calc3 = (powf(point.x, 2) + powf(point.y, 2) + powf(point.z, 2) - powf(radius, 2));
	res1 = -(calc2/(2*calc1));
	delta = powf(calc2, 2) - (4 * calc1 * calc3);
	if (delta < 0)
		nb = 0;
	first.x = point.x + (res1 * vector.x);
	first.y = point.y + (res1 * vector.y);
	first.z = point.z + (res1 * vector.z);
	if (delta > 0) {
		nb = 2;
		res1 = (-calc2 - sqrt(delta))/(2 * calc1);
		res2 = (-calc2 + sqrt(delta))/(2 * calc1);
		first.x = point.x + (res1 * vector.x);
		first.y = point.y + (res1 * vector.y);
		first.z = point.z + (res1 * vector.z);
		second.x = point.x + (res2 * vector.x);
		second.y = point.y + (res2 * vector.y);
		second.z = point.z + (res2 * vector.z);
	}
	printf("sphere of radius %d\n", radius);
	display_point(nb, first, second, point, vector);
}

void     cylindre(char **av)
{
	struct point_t	point;
	struct vec_t	vector;
	int	radius = my_getnbr(av[8]);
	int	nb = 1;
	double	calc1 = 0;
	double	calc2 = 0;
	double	calc3 = 0;
	double	res1 = 0;
	double	res2;
	double	delta = 0;
	struct point_t	first;
	struct point_t	second;

	point.x = my_getnbr(av[2]);
	point.y = my_getnbr(av[3]);
	point.z = my_getnbr(av[4]);
	vector.x = my_getnbr(av[5]);
	vector.y = my_getnbr(av[6]);
	vector.z = my_getnbr(av[7]);
	calc1 = (powf(vector.x, 2) + powf(vector.y, 2));
	calc2 = ((2 * vector.x * point.x) + (2 * vector.y * point.y));
	calc3 = (powf(point.x, 2) + powf(point.y, 2) - powf(radius, 2));
	res1 = -(calc2/(2*calc1));
	delta = powf(calc2, 2) - (4 * calc1 * calc3);
	if (delta < 0)
		nb = 0;
	first.x = point.x + (res1 * vector.x);
	first.y = point.y + (res1 * vector.y);
	first.z = point.z + (res1 * vector.z);
	if (delta > 0) {
		nb = 2;
		res1 = (-calc2 - sqrt(delta))/(2 * calc1);
		res2 = (-calc2 + sqrt(delta))/(2 * calc1);
		first.x = point.x + (res1 * vector.x);
		first.y = point.y + (res1 * vector.y);
		first.z = point.z + (res1 * vector.z);
		second.x = point.x + (res2 * vector.x);
		second.y = point.y + (res2 * vector.y);
		second.z = point.z + (res2 * vector.z);
	}
	printf("cylinder of radius %d\n", radius);
	display_point(nb, first, second, point, vector);
}

void     my_cone(char **av)
{
	int	angle = my_getnbr(av[8]);
	struct point_t	point;
	struct vec_t	vector;
	double	div = 0;
	int	nb = 1;
	double	calc1 = 0;
	double	calc2 = 0;
	double	calc3 = 0;
	double	res1 = 0;
	double	res2;
	double	delta = 0;
	struct point_t	first;
	struct point_t	second;

	point.x = my_getnbr(av[2]);
	point.y = my_getnbr(av[3]);
	point.z = my_getnbr(av[4]);
	vector.x = my_getnbr(av[5]);
	vector.y = my_getnbr(av[6]);
	vector.z = my_getnbr(av[7]);
	div = tan((angle * 2 * PI) / 180);
	calc1 = (powf(vector.x, 2) + powf(vector.y, 2) - (powf(vector.z, 2) / powf(div, 2)));
	calc2 = ((2 * vector.x * point.x) + (2 * vector.y * point.y) - ((2 * vector.z * point.z) / powf(div, 2)));
	calc3 = (powf(point.x, 2) + powf(point.y, 2) - (powf(point.z, 2) / powf(div, 2)));
	res1 = -(calc2/(2*calc1));
	delta = powf(calc2, 2) - (4 * calc1 * calc3);
	if (delta < 0)
		nb = 0;
	first.x = point.x + (res1 * vector.x);
	first.y = point.y + (res1 * vector.y);
	first.z = point.z + (res1 * vector.z);
	if (delta > 0)
	{
		nb = 2;
		res1 = (-calc2 - sqrt(delta))/(2 * calc1);
		res2 = (-calc2 + sqrt(delta))/(2 * calc1);
		first.x = point.x + (res1 * vector.x);
		first.y = point.y + (res1 * vector.y);
		first.z = point.z + (res1 * vector.z);
		second.x = point.x + (res2 * vector.x);
		second.y = point.y + (res2 * vector.y);
		second.z = point.z + (res2 * vector.z);
	}
	printf("cone of %d degree angle\n", angle);
	display_point(nb, first, second, point, vector);
}

int	main(int ac, char **av)
{
	if (ac != 9) {
		printf("error: enter 8 arguments\n");
		return (84);
	}
	if (av[1][0] > '3' || av[1][0] == '0') {
		printf("error: options must be under 3\n");
		return (84);
	}
	if (av[1][0] == '3' && my_getnbr(av[8]) > 360) {
		printf("error: angle must be between 0 and 360 degrees\n");
		return (84);
	}
	if (av[5][0] == '0' && av[6][0] == '0' && av[7][0] == '0') {
		printf("erreur: vecteur cannot be 0 !\n");
		return (84);
	}
	if (av[1][0] == '1' )
		sphere(av);
	if (av[1][0] == '2' )
		cylindre(av);
	if (av[1][0] == '3' )
		my_cone(av);
	return (0);
}
