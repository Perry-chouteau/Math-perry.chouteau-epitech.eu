/*
** EPITECH PROJECT, 2020
** Mat
** File description:
** print_str.c
*/

#include "../includes/102architect.h"

architec_t rm_zero(architec_t aretourner)
{
    if (aretourner.mxyz[0] < 0.01 && aretourner.mxyz[0] > -0.01)
        aretourner.mxyz[0] = 0.00;
    if (aretourner.mxyz[1] < 0.01 && aretourner.mxyz[1] > -0.01)
        aretourner.mxyz[1] = 0.00;
    if (aretourner.mxyz[2] < 0.01 && aretourner.mxyz[2] > -0.01)
        aretourner.mxyz[2] = 0.00;
    if (aretourner.mxyz[3] < 0.01 && aretourner.mxyz[3] > -0.01)
        aretourner.mxyz[3] = 0.00;
    if (aretourner.mxyz[4] < 0.01 && aretourner.mxyz[4] > -0.01)
        aretourner.mxyz[4] = 0.00;
    if (aretourner.mxyz[5] < 0.01 && aretourner.mxyz[5] > -0.01)
        aretourner.mxyz[5] = 0.00;
    if (aretourner.mxyz[6] < 0.01 && aretourner.mxyz[6] > -0.01)
        aretourner.mxyz[6] = 0.00;
    if (aretourner.mxyz[7] < 0.01 && aretourner.mxyz[7] > -0.01)
        aretourner.mxyz[7] = 0.00;
    if (aretourner.mxyz[8] < 0.01 && aretourner.mxyz[8] > -0.01)
        aretourner.mxyz[8] = 0.00;
    return aretourner;
}

int info(architec_t ark)
{
    if (ark.save.cp_av[ark.save.i][0] == '-')
        switch (ark.save.cp_av[ark.save.i][1]) {
            case 't':
                printf("Translation along vector (%s, %s)\n", \
                ark.save.cp_av[ark.save.i + 1], ark.save.cp_av[ark.save.i + 2]);
                return (ark.save.i + 2);
            case 'z':
                printf("Scaling by factors %s and %s\n",    \
                ark.save.cp_av[ark.save.i + 1], ark.save.cp_av[ark.save.i + 2]);
                return (ark.save.i + 2);
            case 'r':
                printf("Rotation by a %s degree angle\n",   \
                ark.save.cp_av[ark.save.i + 1]);
                return (ark.save.i + 1);
            case 's':
                printf("Reflection over an axis with an inclination angle of %s degrees\n", \
                ark.save.cp_av[ark.save.i + 1]);
                return (ark.save.i + 1);
            default:
                exit(84);
        }
}

void write_info(architec_t ark)
{
    ark.save.i = 3;
    for (; ark.save.i < ark.save.cp_ac; ark.save.i += 1) {
        error_info(ark);
        ark.save.i = info(ark);
    }
    return ;
}

void write_result(architec_t ark)
{
    ark.res_xy[0] += (ark.val_xy[0] * ark.mxyz[0]) +    \
    (ark.val_xy[1] * ark.mxyz[1]) + (ark.val_xy[2] * ark.mxyz[2]);
    ark.res_xy[1] += (ark.val_xy[0] * ark.mxyz[3]) +    \
    (ark.val_xy[1] * ark.mxyz[4]) + (ark.val_xy[2] * ark.mxyz[5]);
    ark.res_xy[2] += (ark.val_xy[0] * ark.mxyz[6]) +    \
    (ark.val_xy[1] * ark.mxyz[7]) + (ark.val_xy[2] * ark.mxyz[8]);
    printf("%.2f  %.2f  %.2f\n", ark.mxyz[0], ark.mxyz[1], ark.mxyz[2]);
    printf("%.2f  %.2f  %.2f\n", ark.mxyz[3], ark.mxyz[4], ark.mxyz[5]);
    printf("%.2f  %.2f  %.2f\n", ark.mxyz[6], ark.mxyz[7], ark.mxyz[8]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", ark.val_xy[0], ark.val_xy[1],  \
    ark.res_xy[0], ark.res_xy[1]);
    return ;
}

void print_str(architec_t ark)
{
    write_info(ark);
    ark = write_matrice(ark);
    ark = rm_zero(ark);
    write_result(ark);
    return ;
}