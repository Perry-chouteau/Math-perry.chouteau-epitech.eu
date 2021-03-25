/*
** EPITECH PROJECT, 2020
** ball_bat_ex6.c
** File description:
** ball_bat
*/

#include "../includes/bs_pong.h"
#include <stdlib.h>
#include <math.h>

int ball_bat(float x1, float y1, float z1, float x2, float y2, float z2, float n)
{
    float *xyz_by_n = malloc(sizeof(float) * 3);
    xyz_by_n = pos_by_time(x1,y1,z1,x2,y2,z2,n);
    
    if(xyz_by_n[2] > 0)
        return 0;
    else
        return 1;
}
