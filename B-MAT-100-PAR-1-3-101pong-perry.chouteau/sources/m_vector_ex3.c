/*
** EPITECH PROJECT, 2020
** m_vector.c
** File description:
** m_vector
*/
#include "../includes/bs_pong.h"
#include <stdlib.h>

float *m_vector(float m, float *xyz)
{
    float *mxyz = malloc(sizeof(float) * 3);
    
    for(int i = 0; i <= 2; i += 1)
        mxyz[i] = xyz[i] * (m + 1);
    return mxyz;
}

