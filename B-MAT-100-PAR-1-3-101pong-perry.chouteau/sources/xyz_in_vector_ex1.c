/*
** EPITECH PROJECT, 2020
** xyz_in_vector_ex1.c
** File description:
** Create a function that takes 3 coordinates , and and returns the corresponding vector
*/

#include <stdlib.h>

float *xyz_in_vector(float x, float y, float z)
{
    float *xyz = malloc(sizeof(float)*3);
    
    for(int i = 0; i <= 2; i += 1) {
        xyz[0] = x;
        xyz[1] = y;
        xyz[2] = z;
    }
    return xyz;
}
