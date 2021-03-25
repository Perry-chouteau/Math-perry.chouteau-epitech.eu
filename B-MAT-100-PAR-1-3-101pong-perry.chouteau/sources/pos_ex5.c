/*
** EPITECH PROJECT, 2020
** pos_ex5.c
** File description:
** pos_ex5
*/
#include "../includes/bs_pong.h"
#include <stdlib.h>

float *pos_by_time(float x1, float y1, float z1, float x2, float y2, float z2, float n)
{
    float *xyz_by_n = malloc(sizeof(float) * 3);

    xyz_by_n = m_vector(n,                                              \
                        diff_vector(xyz_in_vector(x1, y1, z1),          \
                                    xyz_in_vector(x2, y2, z2)));
    return xyz_by_n;
}
