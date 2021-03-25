/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-bs104intersection-perry.chouteau
** File description:
** ex4.c
*/

#include "../includes/math.h"

float *def_line_pos(float *p, float *vect, float t)
{
    float *new_p = malloc(sizeof(float) * 3);
    for (int i = 0; i < 3; i += 1)
        new_p[i] = p[i] + vect[i] * t;
    return new_p; 
}

/*|   ./intersection | p[0], p[1], p[2], vect[0], vect[1], vect[2], t    |*/

/*int main(int ac, char **av)
{
    float *p = malloc(sizeof(float) * 3);
    float *vect = malloc(sizeof(float) * 3);
    float t = atof(av[7]);

    for (int i = 0; i < 3; i += 1)
        p[i] = atof(av[1 + i]);
    for (int i = 0; i < 3; i += 1)
        vect[i] = atof(av[4 + i]);
    float *new_p = def_line_pos(p, vect, t);
    printf("|>%f\t", new_p[0]);
    printf("|>%f\t", new_p[1]);
    printf("|>%f\t", new_p[2]);
    printf("\n");
    return 0;
}*/

