/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include <math.h>
#include "103.h"

void	decrypt(char **av, int *msg)
{
	int   size = strlen(av[2]);

	if (size <= 4)
		little_reverse(av, msg);
	if (size > 4 && size <= 9)
		big_reverse(msg);
}

int	little_reverse(char **av, int *msg)
{
	float res;
	float rev[4];

	if ((res = (msg[0] * msg[3]) - (msg[2] * msg[1])) == 0) {
		printf("Determinant is equal 0, unable to reverse matrix\n");
		return (0);
	}
	rev[0] = msg[3] / res;
	rev[1] = (-msg[1]) / res;
	rev[2] = (-msg[2]) / res;
	rev[3] = msg[0] / res;
	printf("Key matrix :\n");
	printf("%.3f  %.3f\n", rev[0], rev[1]);
	printf("%.3f  %.3f\n", rev[2], rev[3]);
	little_decrypt(av, rev);
	return (0);
}

void	little_decrypt(char **av, float *reverse)
{
	int   cpt = 0;
	int   nb1 = 0;
	int   nb2 = 0;
	int   len;
	float res1;
	float res2;
	int   res;

	len = strlen(av[1]);
	printf("\nDecrypted message :\n");
	for (cpt = cpt ; (cpt < len) ; cpt++) {
		for (cpt = cpt ; (av[1][cpt] && av[1][cpt] != ' ') ; cpt++) {
			res = av[1][cpt] - 48;
			nb1 = nb1 * 10 + res;
		}
		cpt += 1;
		for (cpt = cpt ; (av[1][cpt] && av[1][cpt] != ' ') ; cpt++) {
			res = av[1][cpt] - 48;
			nb2 = nb2 * 10 + res;
		}
		res1 = round(nb1 * reverse[0] + nb2 * reverse[2]);
		res2 = round(nb1 * reverse[1] + nb2 * reverse[3]);
		printf("%c%c", (int)res1, (int)res2);
		cpt += 1;
	}
	printf("\n");
}

int	big_reverse(int *msg)
{
	float res;
	float rev[9];

	if ((res = msg[0] * (msg[4]*msg[8] - msg[5]*msg[7])
	     - msg[3] * (msg[1]*msg[8] - msg[2]*msg[7])
	     + msg[6] * (msg[1]*msg[5] - msg[2]*msg[4])) == 0) {
		printf("Determinant is equal 0, unable to reverse matrix\n");
		return (0);
	} else {
		printf("%.3f\n", res);
		rev[0] = (msg[4] * msg[8] - msg[5] * msg[7]) / res;
		rev[1] = -(msg[1] * msg[8] - msg[2] * msg[7]) / res;
		rev[2] = (msg[1] * msg[5] - msg[2] * msg[4]) / res;
		rev[3] = -(msg[3] * msg[8] - msg[5] * msg[6]) / res;
		rev[4] = (msg[0] * msg[8] - msg[2] * msg[6]) / res;
		rev[5] = -(msg[0] * msg[5] - msg[2] * msg[3]) / res;
		rev[6] = (msg[3] * msg[7] - msg[4] * msg[6]) / res;
		rev[7] = -(msg[0] * msg[7] - msg[1] * msg[6]) / res;
		rev[8] = (msg[0] * msg[4] - msg[1] * msg[3]) / res;
		
		printf("Key matrix :\n");
		printf("%.3f\t%.3f\t%.3f\n", rev[0], rev[1], rev[2]);
		printf("%.3f\t%.3f\t%.3f\n", rev[3], rev[4], rev[5]);
		printf("%.3f\t%.3f\t%.3f\n", rev[6], rev[7], rev[8]);
	}
	return (0);
}

void	decript_size_one(char **av)
{
	int   ascii = av[2][0];
	int   cpt = 0;
	int   res;
	int   size = strlen(av[1]);
	int   nb = 0;
	int   carac = 0;

	printf("Key matrix :\n%d\n\nDecrypted message :\n", ascii);
	while (cpt < size) {
		nb = 0;
		while (av[1][cpt] != ' ' && av[1][cpt] != '\0') {
			carac = av[1][cpt] - 48;
			nb = nb * 10 + carac;
			cpt = cpt + 1;
		}
		res = nb / ascii;
		printf("%c", res);
		cpt += 1;
	}
	printf("\n");
}

void	cript_size_one(char **av)
{
	int   ascii = av[2][0];
	int   cpt = 0;
	int   nb = 0;
	int   size = strlen(av[1]);

	printf("Key :\n%d\n\nEncrypted message :\n", ascii);
	while (cpt < size) {
		nb = av[1][cpt] * ascii;
		printf("%d", nb);
		cpt = cpt + 1;
		if (cpt < size)
			printf(" ");
	}
	printf("\n");
}

void	big_msg(char **av, int *msg)
{
	int   size = strlen(av[1]);
	int   res1 = 0;
	int   res2 = 0;
	int   res3 = 0;
	int   res4 = 0;
	int   cpt = 0;

	printf("%d\t%d\t%d\t%d\n", msg[0], msg[1], msg[2], msg[3]);
	printf("%d\t%d\t%d\t%d\n", msg[4], msg[5], msg[6], msg[7]);
	printf("%d\t%d\t%d\t%d\n", msg[8], msg[9], msg[10], msg[11]);
	printf("%d\t%d\t%d\t%d\n\n", msg[12], msg[13], msg[14], msg[15]);
	printf("Encrypted message :\n");
	while (cpt + 3 < size) {
		res1 = av[1][cpt] * msg[0] + av[1][cpt + 1] * msg[4] + av[1][cpt + 2] * msg[8] + av[1][cpt + 3] * msg[12];
		res2 = av[1][cpt] * msg[1] + av[1][cpt + 1] * msg[5] + av[1][cpt + 2] * msg[9] + av[1][cpt + 3] * msg[13];
		res3 = av[1][cpt] * msg[2] + av[1][cpt + 1] * msg[6] + av[1][cpt + 2] * msg[10] + av[1][cpt + 3] * msg[14];
		res4 = av[1][cpt] * msg[3] + av[1][cpt + 1] * msg[7] + av[1][cpt + 2] * msg[11] + av[1][cpt + 3] * msg[15];
		printf("%d %d %d %d", res1, res2, res3, res4);
		cpt += 4;
		if (cpt + 3 < size)
			printf(" ");
	}
	if (cpt < size) {
		res1 = av[1][cpt] * msg[0];
		res2 = av[1][cpt] * msg[1];
		res3 = av[1][cpt] * msg[2];
		res4 = av[1][cpt] * msg[3];
		printf(" %d %d %d %d", res1, res2, res3, res4);
	}
	res1 = av[1][cpt] * msg[0] + av[1][cpt + 1] * msg[4];
	res2 = av[1][cpt] * msg[1] + av[1][cpt + 1] * msg[5];
	res3 = av[1][cpt] * msg[2] + av[1][cpt + 1] * msg[6];
	res4 = av[1][cpt] * msg[3] + av[1][cpt + 1] * msg[7];
	printf(" %d %d %d %d", res1, res2, res3, res4);
	if (cpt + 2 < size) {
		res1 = av[1][cpt] * msg[0] + av[1][cpt + 1] * msg[4] + av[1][cpt + 2] * msg[8];
		res2 = av[1][cpt] * msg[1] + av[1][cpt + 1] * msg[5] + av[1][cpt + 2] * msg[9];
		res3 = av[1][cpt] * msg[2] + av[1][cpt + 1] * msg[6] + av[1][cpt + 2] * msg[10];
		res4 = av[1][cpt] * msg[3] + av[1][cpt + 1] * msg[7] + av[1][cpt + 2] * msg[11];
		printf("%d %d %d %d", res1, res2, res3, res4);
	}
	putchar('\n');
}

void	middle_msg(char **av, int *msg)
{
	int   size = strlen(av[1]);;
	int   res1 = 0;
	int   res2 = 0;
	int   res3 = 0;
	int   cpt = 0;

	printf("%d\t%d\t%d\n", msg[0], msg[1], msg[2]);
	printf("%d\t%d\t%d\n", msg[3], msg[4], msg[5]);
	printf("%d\t%d\t%d\n\n", msg[6], msg[7], msg[8]);
	puts("Encrypted message :");
	while (cpt + 2 < size) {
		res1 = av[1][cpt] * msg[0] + av[1][cpt + 1] * msg[3] + av[1][cpt + 2] * msg[6];
		res2 = av[1][cpt] * msg[1] + av[1][cpt + 1] * msg[4] + av[1][cpt + 2] * msg[7];
		res3 = av[1][cpt] * msg[2] + av[1][cpt + 1] * msg[5] + av[1][cpt + 2] * msg[8];
		printf("%d %d %d", res1, res2, res3);
		cpt += 3;
		if (cpt + 2 < size)
			printf(" ");
	}
	if (cpt < size) {
		res1 = av[1][cpt] * msg[0] + 0 * msg[3] + 0 * msg[6];
		res2 = av[1][cpt] * msg[1] + 0 * msg[4] + 0 * msg[7];
		res3 = av[1][cpt] * msg[2] + 0 * msg[5] + 0 * msg[8];
		printf(" %d %d %d", res1, res2, res3);
	}
	if (cpt + 1 < size) {
		res1 = av[1][cpt] * msg[0] + av[1][cpt + 1] * msg[3] + 0 * msg[6];
		res2 = av[1][cpt] * msg[1] + av[1][cpt + 1] * msg[4] + 0 * msg[7];
		res3 = av[1][cpt] * msg[2] + av[1][cpt + 1] * msg[5] + 0 * msg[8];
		printf(" %d %d %d", res1, res2, res3);
	}
	putchar('\n');
}

void	little_msg(char **av, int *msg)
{
	int   size = strlen(av[1]);
	int   res1 = 0;
	int   res2 = 0;
	int   cpt = 0;

	printf("%d\t%d\n", msg[0], msg[1]);
	printf("%d\t%d\n\n", msg[2], msg[3]);
	printf("Encrypted message :\n");
	while (cpt + 1 < size) {
		res1 = av[1][cpt] * msg[0] + av[1][cpt + 1] * msg[2];
		res2 = av[1][cpt] * msg[1] + av[1][cpt + 1] * msg[3];
		printf("%d %d", res1, res2);
		cpt += 2;
		if (cpt + 1 < size)
			printf(" ");
	}
	if (cpt < size) {
		res1 = av[1][cpt] * msg[0] + 0 * msg[2];
		res2 = av[1][cpt] * msg[1] + 0 * msg[3];
		printf(" %d %d", res1, res2);
	}
	putchar('\n');
}

int	*my_msg_matrix(char **av)
{
	int     size = strlen(av[2]);
	int     *msg;
	int     cpt = 0;

	if (size > 1 && size <= 4) {
		msg = malloc(sizeof(int) * 4);
		for (cpt = cpt ; (cpt < size) ; cpt++)
			msg[cpt] = av[2][cpt];
		for (size = size ; (size < 4) ; size++)
			msg[size] = 0;
	}
	if (size >4 && size <= 9) {
		msg = malloc(sizeof(int) * 9);
		for (cpt = cpt ; (cpt < size)	; cpt++)
			msg[cpt] = av[2][cpt];
		for (size = size ; (size < 9) ; size++)
			msg[size] = 0;
	}
	if (size > 9 && size <= 16) {
		msg = malloc(sizeof(int) * 16);
		for (cpt = cpt ; (cpt < size) ; cpt++)
			msg[cpt] = av[2][cpt];
		for (size = size ; (size < 12) ; size++)
			msg[size] = 0;
	}
	return (msg);
}

int	main(int ac, char **av)
{
	int     *msg = my_msg_matrix(av);;
	int     size = strlen(av[2]);

	if (ac != 4)
		return (84);
	if ((my_getnb(av[3]) != 1 && my_getnb(av[3]) != 1 && strlen(av[3]) != 1) || is_num(av[3][0]) == 0)
		return (84);
	if (my_getnb(av[3]) == 0) {
		if (size == 1)
			cript_size_one(av);
		if (size > 1) {
			puts("Key matrix :");
			if (strlen(av[2]) < 5)
				little_msg(av, msg);
			if (strlen(av[2]) > 4 && strlen(av[2]) < 10)
				middle_msg(av, msg);
			if (strlen(av[2]) > 9 && strlen(av[2]) < 17)
				big_msg(av, msg);
		}
	}
	if (my_getnb(av[3]) == 1) {
		if (size == 1)
			decript_size_one(av);
		if (size > 1)
			decrypt(av, msg);
	}
	return (0);
}
