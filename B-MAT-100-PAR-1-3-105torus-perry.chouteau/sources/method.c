/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-105torus-perry.chouteau
** File description:
** bisection_method.c
*/

#include "../includes/torus.h"

int bisection(torus_t tor)
{
    double a = 0;
    double b = 1;
    double c = 0.5;

    for (int i = 0 ; fabs(f_x(tor.a, c)) > pow(10, (-1 * tor.n));) {
        c = (a + b) / 2;
        if (f_x(tor.a, a) * f_x(tor.a, c) < 0) {
            if (c - b  >= b - a)
                return 84;
            b = c;
        } else {
            if (c - a >= b - a)
                return 84;
            a = c;
        }
        if (i < tor.n)
            i += 1;
        printf("x = %.*f\n", i, c);
    }
    return 0;
}

int newton(torus_t tor)
{
    double x1 = 0.5;
    double temp;
    double temp2;

    if (fp_x(tor.a, x1) == 0)
        return 84;
    temp = x1 - (f_x(tor.a, x1) / fp_x(tor.a, x1));
    temp2 = temp - (f_x(tor.a, x1) / fp_x(tor.a, x1));
    if (fabs(x1) - fabs(temp) > (temp) - fabs(temp2))
        return 84;
    printf("x = %.1f\n", x1);
    for (; fabs(f_x(tor.a, x1)) > pow(10, (-1 * tor.n)); ) {
        if (fp_x(tor.a, x1) == 0)
            return 84;
        x1 -= (f_x(tor.a, x1) / fp_x(tor.a, x1));
        printf("x = %.*f\n", tor.n, x1);
    }
    return 0;
}

int secant(torus_t tor)
{
    double fx = 0;
    double fy = 1;
    double temp = 0;

    for (int i = 0; fabs(f_x(tor.a, fy)) > pow(10, (-1 * tor.n)) && i < 300; \
    i += 1) {
        temp = fy;
        if ((f_x(tor.a, fy) - f_x(tor.a, fx)) == 0)
            return 84;
        fy -= ((f_x(tor.a, fy) * (fy - fx)) /   \
        (f_x(tor.a, fy) - f_x(tor.a, fx)));
        fx = temp;
        if (i == 0)
            printf("x = %.*g\n", tor.n,fy);
        else
            printf("x = %.*f\n", tor.n, fy);
    }
    return 0;
}