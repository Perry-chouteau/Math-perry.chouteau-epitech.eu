/*
** EPITECH PROJECT, 2020
** Mat
** File description:
** matrice.c
*/

#include "../includes/102architect.h"

architec_t matrice1(architec_t ark)
{
    if (ark.save.cp_av[ark.save.i][0] == '-' && \
    ark.save.cp_av[ark.save.i][1] == 't') {
        if (ark.save.cp_av[ark.save.i + 2] == NULL)
            exit(84);
        ark.save.i += 1;
        ark.mxyz[2] += atof(ark.save.cp_av[ark.save.i]);
        ark.save.i += 1;
        ark.mxyz[5] += atof(ark.save.cp_av[ark.save.i]);
    }
    if (ark.save.cp_av[ark.save.i][0] == '-' &&    \
    ark.save.cp_av[ark.save.i][1] == 'z') {
        if (ark.save.cp_av[ark.save.i + 2] == NULL)
            exit(84);
        ark.save.i += 1;
        ark.mxyz[0] *= atof(ark.save.cp_av[ark.save.i]);
        ark.save.i += 1;
        ark.mxyz[4] *= atof(ark.save.cp_av[ark.save.i]);
    }
    return ark;
}

architec_t matrice2(architec_t ark)
{
    if (ark.save.cp_av[ark.save.i][0] == '-' && \
    ark.save.cp_av[ark.save.i][1] == 's') {
        ark.save.i += 1;
        ark.mxyz[0] *= roundf(cosf(RAD(2 * atof(ark.save.cp_av[ark.save.i]))));
        ark.mxyz[1] += roundf(sinf(RAD(2 * atof(ark.save.cp_av[ark.save.i]))));
        ark.mxyz[3] += roundf(sinf(RAD(2 * atof(ark.save.cp_av[ark.save.i]))));
        ark.mxyz[4] *= roundf(-cosf(RAD(2 * atof(ark.save.cp_av[ark.save.i]))));
        }
    if (ark.save.cp_av[ark.save.i][0] == '-' &&  \
    ark.save.cp_av[ark.save.i][1] == 'r') {
        ark.save.i += 1;
        ark.mxyz[0] *= cosf(RAD(atof(ark.save.cp_av[ark.save.i])));
        ark.mxyz[1] += -sinf(RAD(atof(ark.save.cp_av[ark.save.i])));
        ark.mxyz[3] += sinf(RAD(atof(ark.save.cp_av[ark.save.i])));
        ark.mxyz[4] *= cosf(RAD(atof(ark.save.cp_av[ark.save.i])));
    }
    return ark;
}

architec_t write_matrice(architec_t ark)
{
    ark.save.i = 3;
    for (; ark.save.i < ark.save.cp_ac; ark.save.i  += 1) {
        ark = matrice1(ark);
        ark = matrice2(ark);
    }
    return ark;
}