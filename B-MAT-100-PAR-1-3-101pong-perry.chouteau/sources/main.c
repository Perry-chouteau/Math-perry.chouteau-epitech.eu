/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../includes/bs_pong.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int ac,char **argv)
{
    if (ac != 8 || argv[1] == argv[4] &&                \
        argv[2] == argv[5] && argv[3] == argv[6])
        return 84;
    if(atof(argv[7]) < 0)
        return 84;
    for(int i = 1; i < ac; i += 1)
        for(int j = 0; argv[i][j] != '\0'; j += 1)
            if((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '.' && argv[i][j] != '-')
                return 84;
    
    float t = atof(argv[7]);
    float *xyz;
    float angle;
    float *diff_xyz = diff_vector(xyz_in_vector(atof(argv[1]),          \
                                                atof(argv[2]),          \
                                                atof(argv[3])),         \
                                  xyz_in_vector(atof(argv[4]),          \
                                                atof(argv[5]),          \
                                                atof(argv[6])));

    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", diff_xyz[0], diff_xyz[1], diff_xyz[2]);
    xyz = sum_vector(xyz_in_vector(atof(argv[1]),          \
                                   atof(argv[2]),          \
                                   atof(argv[3])),         \
                     m_vector(t, diff_xyz));
    printf("At time t + %.0f, ball coordinates will be:\n", t);
    printf("(%.2f, %.2f, %.2f)\n", xyz[0], xyz[1], xyz[2]);
    if (ball_bat(atof(argv[1]),               \
                 atof(argv[2]),               \
                 atof(argv[3]),               \
                 atof(argv[4]),               \
                 atof(argv[5]),               \
                 atof(argv[6]),               \
                 atof(argv[7])) == 1) {
        angle = fabs(angle_vector(diff_xyz));
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", angle);
    }
    else
        printf("The ball won't reach the paddle.\n");
}
