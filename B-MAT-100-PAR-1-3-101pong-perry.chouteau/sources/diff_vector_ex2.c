/*
** EPITECH PROJECT, 2020
** diff_vector.c
** File description:
** diff vector
*/

#include <stdlib.h>

float *diff_vector(float *xyz1,float *xyz2)
{
    float *diff_xyz = malloc(sizeof(float) * 3);

    for(int i = 0; i <= 2; i += 1)
        diff_xyz[i] = xyz2[i] - xyz1[i];
    return diff_xyz;
}
