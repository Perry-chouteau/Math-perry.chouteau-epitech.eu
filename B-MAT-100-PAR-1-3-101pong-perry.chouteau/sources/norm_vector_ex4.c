/*
** EPITECH PROJECT, 2020
** norm_vector_ex4.c
** File description:
** norm_vector
*/

#include <math.h>
#include <stdlib.h>

float norm_vector(float *xyz)
{
    float norm_xyz;
    float *pos = malloc(sizeof(float) * 3);
    
    for(int i = 0; i <= 2; i += 1)
        pos[i] =xyz[i] *= xyz[i];
    norm_xyz = sqrtf(pos[0] + pos[1] + pos[2]);
    return norm_xyz;
}
