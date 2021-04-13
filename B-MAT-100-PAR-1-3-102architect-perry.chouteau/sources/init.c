/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-102architect-perry.chouteau
** File description:
** init.c
*/

#include "../includes/102architect.h"

architec_t init(int ac, char **av)
{
    architec_t aretourner;

    aretourner.save.cp_av = av;
    aretourner.save.cp_ac = ac;
    aretourner.mxyz = malloc(sizeof(int) * 9);
    for (int i; i <= 9; i += 1)
        aretourner.mxyz[i] = 0;
    aretourner.mxyz[0] = 1;
    aretourner.mxyz[4] = 1;
    aretourner.mxyz[8] = 1;
    aretourner.save.i = 0;
    aretourner.val_xy = malloc(sizeof(int) * 3);
    if (aretourner.save.cp_av[1][0] != '-') {
        aretourner.val_xy[0] = atof(aretourner.save.cp_av[1]);
        aretourner.val_xy[1] = atof(aretourner.save.cp_av[2]);
    }
    aretourner.val_xy[2] = 1;
    aretourner.res_xy = malloc(sizeof(int) * 3);
    aretourner.res_xy[0] = 0;
    aretourner.res_xy[1] = 0;
    aretourner.res_xy[2] = 0;
    return aretourner;
}