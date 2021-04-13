/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** two_list.c
*/

#include "../includes/include.h"

int transfer(list_t *list, int ac)
{
    double *x = malloc(sizeof(double) * (ac));
    double res;

    for (double k = 0; k <= 1.001; k += 0.001) {
        for (int i = 0; i < (ac - 1); i += 1) {
            x[i] = 0;
            for (int j = 0; j < list[i].len; j += 1)
                x[i] += list[i].number[j] * pow(k, j);
        }
        res = 1;
        for (int i = 0; i < (ac - 1); i += 2) {
            res *= (x[i] / x[i + 1]);
        }
        printf("%.3f -> %.5f\n", k, res);
    }
    return 0;
}