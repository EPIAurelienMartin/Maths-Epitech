/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "architecte.h"

void    aff_matrice(double *mat)
{
	int   cpt = 0;
	double	res = 0;

	while (cpt < 9) {
		res = mat[cpt];
		if (res < 0.0050 && res > -0.0050)
			res = 0.00;
		printf("%.2f", res);
		cpt += 1;
		if (cpt % 3 == 0) {
			putchar('\n');
		}
		else
			putchar('\t');
	}
}
double  *my_multiply(double *mat1, double *mat2)
{
	double *res;

	res = malloc(10);
	res[0] = (mat1[0] * mat2[0]) + (mat1[1] * mat2[3]) + (mat1[2] * mat2[6]);
	res[1] = (mat1[0] * mat2[1]) + (mat1[1] * mat2[4]) + (mat1[2] * mat2[7]);
	res[2] = (mat1[0] * mat2[2]) + (mat1[1] * mat2[5]) + (mat1[2] * mat2[8]);
	res[3] = (mat1[3] * mat2[0]) + (mat1[4] * mat2[3]) + (mat1[5] * mat2[6]);
	res[4] = (mat1[3] * mat2[1]) + (mat1[4] * mat2[4]) + (mat1[5] * mat2[7]);
	res[5] = (mat1[3] * mat2[2]) + (mat1[4] * mat2[5]) + (mat1[5] * mat2[8]);
	res[6] = (mat1[6] * mat2[0]) + (mat1[7] * mat2[3]) + (mat1[8] * mat2[6]);
	res[7] = (mat1[6] * mat2[1]) + (mat1[7] * mat2[4]) + (mat1[8] * mat2[7]);
	res[8] = (mat1[6] * mat2[2]) + (mat1[7] * mat2[5]) + (mat1[8] * mat2[8]);
	res[9] = 0;
	return (res);
}

double  *my_translation(double *res, double *mat, char **av, int cpt)
{
	double	one = atof(av[cpt + 1]);
	double	two = atof(av[cpt + 2]);
		
	mat[2] = mat[2] + one;
	mat[5] = mat[5] + two;
	res[0] = res[0] + one;
	res[1] = res[1] + two;
	printf("Translation by the vector (%.0f, %.0f)\n", one, two);
	return (res);
}

double  *my_homothety(double *res, double *mat, char **av, int cpt)
{
	double	one = atof(av[cpt + 1]);
	double	two = atof(av[cpt + 2]);

	mat[0] = mat[0] * one;
	mat[1] = mat[1] * one;
	mat[2] = mat[2] * one;
	mat[3] = mat[3] * two;
	mat[4] = mat[4] * two;
	mat[5] = mat[5] * two;
	res[0] = res[0] * one;
	res[1] = res[1] * two;
	printf("Homothety by the ratios %.0f and %.0f\n", one, two);
	return (res);
}

double  *my_rotation(double *res, double *mat, char **av, int cpt)
{
	double  mat_rota[9];
	double  mem;
	double	one = cos((atof(av[cpt + 1]) * M_PI) / 180);
	double	two = sin(((atof(av[cpt + 1]) * M_PI) / 180));

	mat_rota[0] = one;
	mat_rota[1] = -two;
	mat_rota[2] = 0;
	mat_rota[3] = two;
	mat_rota[4] = one;
	mat_rota[5] = 0;
	mat_rota[6] = 0;
	mat_rota[7] = 0;
	mat_rota[8] = 1;
	mat = my_multiply(mat, mat_rota);
	mem = res[0];
	res[0] = mem * mat_rota[0] + res[1] * mat_rota[1];
	res[1] = mem * mat_rota[3] + res[1] * mat_rota[4];
	printf("Rotation at a %s degree angle\n", av[cpt + 1]);
	return (res);
}

double  *my_symmetry(double *res, double *mat, char **av, int cpt)
{
	double  mat_syme[9];
	double  mem = res[0];
	double	one = cos(2 * ((atof(av[cpt + 1]) * M_PI) / 180));
	double	two = sin(2 * ((atof(av[cpt + 1]) * M_PI) / 180));

	mat_syme[0] = one;
	mat_syme[1] = two;
	mat_syme[2] = 0;
	mat_syme[3] = two;
	mat_syme[4] = -one;
	mat_syme[5] = 0;
	mat_syme[6] = 0;
	mat_syme[7] = 0;
	mat_syme[8] = 1;
	mat = my_multiply(mat, mat_syme);
	res[0] = mem * mat_syme[0] + res[1] * mat_syme[1];
	res[1] = mem * mat_syme[3] + res[1] * mat_syme[4];
	printf("Symmetry about an axis inclined with an angle of %s degrees\n", av[cpt + 1]);
	return (res);
}

void    error_first(char *str, char *str2)
{
	if (str == NULL || str2 == NULL) {
		printf("%s\n", "After option -t && -h, enter two numbers");
		exit (84);
	}
	if (my_str_isnum(str) == 1 || my_str_isnum(str2) == 1) {
		printf("%s\n", "After option -t && -h, enter two numbers");
		exit (84);
	}
}

void    error_second(char *str)
{
	if (str == NULL) {
		printf("%s\n", "After option -r && -s, enter one number");
		exit (84);
	}
	if (my_str_isnum(str) == 1) {
		printf("%s\n", "After option -r && -s, enter one number");
		exit (84);
	}
}

double  *my_check(double *mat, double *res, char **av, int ac)
{
	int	cpt = 3;

	while (cpt < ac) {
		if (strcmp(av[cpt], "-t") == 0) {
			error_first(av[cpt + 1], av[cpt + 2]);
			res = my_translation(res, &mat[0], av, cpt);
			cpt += 3;
		}
		else if (strcmp("-h", av[cpt]) == 0) {
			error_first(av[cpt + 1], av[cpt + 2]);
			res = my_homothety(res, &mat[0], av, cpt);
			cpt += 3;
		}
		else if (strcmp(av[cpt], "-r") == 0) {
			error_second(av[cpt + 1]);
			res = my_rotation(res, &mat[0], av, cpt);
			cpt += 2;
		}
		else if (strcmp(av[cpt], "-s") == 0) {
			error_second(av[cpt + 1]);
			res = my_symmetry(res, &mat[0], av, cpt);
			cpt += 2;
		} else {
			printf("%s\n", "Wrong option. Options are -t, -h, -r -s");
			exit (84);
		}
	}
	return (res);
}

int	main(int ac, char **av)
{
	double        mat[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	double        res[3];

	if (ac < 5) {
		printf("%s", "Not enough argument please enter atleast 5 arguments");
		exit (84);
	}
	res[0] = atof(av[1]);
	res[1] = atof(av[2]);
	res[2] = 1;
	my_check(mat, res, av, ac);
	aff_matrice(mat);
	printf("(%s,%s) => (%.2f,%.2f)\n", av[1], av[2], res[0], res[1]);
	return (0);
}
