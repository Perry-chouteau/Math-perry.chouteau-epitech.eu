/*
** EPITECH PROJECT, 2020
** angle_vector_ex7.c
** File description:
** angle_vector
*/
#include "../includes/bs_pong.h"
#include <math.h>
#define PI 3.1415926535;

float angle_vector(float *xyz)
{
    float angle;
    angle = asinf(xyz[2] / norm_vector(xyz)) * 180 / PI;
    return angle;
}
