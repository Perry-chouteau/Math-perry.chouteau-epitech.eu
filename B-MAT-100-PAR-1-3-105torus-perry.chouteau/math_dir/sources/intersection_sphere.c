/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-bs104intersection-perry.chouteau
** File description:
** intersec__sphere.c
*/

#include <stdlib.h>
#include <stddef.h>

float *intersection_sphere(float *p, float *vect, float r)
{
    float *abc = malloc(sizeof(float) * 3);
    float *itsc;
    int nb_sols;

    if (r <= 0)
        exit(84);
    abc[0] = (vect[0] * vect[0]) + (vect[1] * vect[1]) + (vect[2] * vect[2]);
    abc[1] = 2 *((p[0] * vect[0]) + (p[1] * vect[1]) + (p[2] * vect[2]));
    abc[2] = (p[0] * p[0]) + (p[1] * p[1]) + (p[2] * p[2]);
    abc[2] -= (r * r);
    return abc;
}

/*|   ./intersection | p[0], p[1], p[2], vect[0], vect[1], vect[2], R    |*/

/*int main(int ac, char **av)
{
    float *p = malloc(sizeof(float) * 3);
    float *vect = malloc(sizeof(float) * 3);
    float r = atof(av[7]);
    float *res;

    for (int i = 0; i < 3; i += 1)
        p[i] = atof(av[1 + i]);
    for (int i = 0; i < 3; i += 1)
        vect[i] = atof(av[4 + i]);
    r = atof(av[7]);
    res = intersection_sphere(p, vect, r);
    printf("%f\n", res[0]);
    printf("%f\n", res[1]);
    printf("%f\n", res[2]);
    printf("\n");
    return 0;
}*/