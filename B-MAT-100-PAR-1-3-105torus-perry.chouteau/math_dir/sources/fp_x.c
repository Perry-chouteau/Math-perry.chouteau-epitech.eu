/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-105torus-perry.chouteau
** File description:
** f_prime_x.c
*/

#include "../includes/math.h"

double fp_x(double *f, double x)
{
    return ((4 *f[4] * pow(x, 3)) + (3 * f[3] * pow(x, 2)) +    \
    (2 * f[2] * pow(x, 1)) + (1 * f[1] * pow(x, 0)));
}