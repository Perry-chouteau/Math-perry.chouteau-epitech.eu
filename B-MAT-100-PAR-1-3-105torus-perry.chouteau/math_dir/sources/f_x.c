/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-105torus-perry.chouteau
** File description:
** f_x.c
*/

#include "../includes/math.h"

double f_x(double *f, double x)
{
    return ((f[4] * pow(x, 4)) + (f[3] * pow(x, 3)) +   \
    (f[2] * pow(x, 2)) + (f[1] * pow(x, 1)) + (f[0] * pow(x, 0)));
}