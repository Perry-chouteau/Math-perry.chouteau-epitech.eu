/*
** EPITECH PROJECT, 2020
** sum_vector_ex2.c	
** File description:
** sum_vector
*/

#include <stdlib.h>

float *sum_vector(float *xyz1, float *xyz2)
{
    float *sum_xyz = malloc(sizeof(float)*3);
    
    for(int i = 0; i <= 2; i += 1)
        sum_xyz[i] = xyz1[i] + xyz2[i];
    return sum_xyz;
}
