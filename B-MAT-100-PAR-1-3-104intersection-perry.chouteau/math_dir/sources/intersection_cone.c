/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-bs104intersection-perry.chouteau
** File description:
** intersec__sphere.c
*/

#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "../includes/math.h"

float *intersection_cone(float *p, float *vect, float angl_deg)
{
    float *abc = malloc(sizeof(float) * 3);
    float *itsc;
    abc[0] = pow(vect[0], 2) + pow(vect[1], 2) -    \
    pow(tan(angl_deg / 180 * PI), 2) * pow(vect[2], 2);
    abc[1] = 2 * (p[0] * vect[0] + p[1] * vect[1] - \
    pow(tan(angl_deg / 180 * PI), 2) *  vect[2] * p[2]);
    abc[2] = pow(p[0], 2) + pow(p[1], 2) -  \
    pow(tan(angl_deg / 180 * PI), 2) * pow(p[2], 2);
    return abc;
}

/*|   ./intersection | p[0], p[1], p[2], vect[0], vect[1], vect[2], t    |*/

/*int main(int ac, char **av)
{
    float *p = malloc(sizeof(float) * 3);
    float *vect = malloc(sizeof(float) * 3);
    float t = atof(av[7]);
    float *res;

    for (int i = 0; i < 3; i += 1)
        p[i] = atof(av[2 + i]);
    for (int i = 0; i < 3; i += 1)
        vect[i] = atof(av[5 + i]);
    t = atof(av[8]);
    res = intersection_cone(p, vect, t);
    printf("%f\n", p[0]);
    printf("%f\n", p[1]);
    printf("%f\n", p[2]);
    printf("\n");
    printf("%f\n", vect[0]);
    printf("%f\n", vect[1]);
    printf("%f\n", vect[2]);
    printf("\n");
    printf("%f\n", res[0]);
    printf("%f\n", res[1]);
    printf("%f\n", res[2]);
    printf("\n");
    return 0;
    //(-1.568, -1.568, -3.842)
    //(-0.537, -0.537, 1.315)
}*/