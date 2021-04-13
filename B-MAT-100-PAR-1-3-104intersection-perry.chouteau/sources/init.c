/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-pushswap-perry.chouteau
** File description:
** init.c
*/

#include "../includes/intersection.h"

// describe / error / init

void describe(void)
{
    my_printf("USAGE\n");
    my_printf("\t./104intersection opt xp yp zp xv yv zv p\n");
    my_printf("\n");
    my_printf("DESCRIPTION\n");
    my_printf("\topt\t\tsurface option: 1 for a sphere, 2 for a cyl xinder, 3 for a cone\n");
    my_printf("\t(xp, yp, zp)\tcoordinates of a point by which the light ray passes through\n");
    my_printf("\t(xv, yv, zv)\tcoordinates of a vector parallel to the light ray\n");
    my_printf("\tp\t\tparameter: radius of the sphere, radius of the cylinder, or\n");
    my_printf("\t\t\tangle formed by the cone and the Z-axis\n");
    exit(0);
}

int my_error(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0 &&   \
    my_strlen(av[1]) == 2)
        describe();
    if (ac != 9)
        exit(84);
    for (int i = 1; i < ac; i += 1)
        if (my_str_isnum(av[i]) == 0)
            exit(84);
    if (atof(av[5]) == 0 && atof(av[6]) == 0 && \
    atof(av[7]) == 0)
        exit(84);
    if (atof(av[8]) <= 0)
        exit(84);
    if (atof(av[1]) == 3 && (atof(av[8]) % 90) == 0)
    return 0;
}

is_t init(int ac, char **av)
{
    is_t aretourner;
    aretourner.opt = atoi(av[1]);
    aretourner.p = malloc(sizeof(float) * 3);
    aretourner.v = malloc(sizeof(float) * 3);
    for (int i = 0; i < 3; i += 1)
        aretourner.p[i] = atof(av[2 + i]);
    for (int i = 0; i < 3; i += 1)
        aretourner.v[i] = atof(av[5 + i]);
    aretourner.r_a = atof(av[8]);
    return aretourner;
}