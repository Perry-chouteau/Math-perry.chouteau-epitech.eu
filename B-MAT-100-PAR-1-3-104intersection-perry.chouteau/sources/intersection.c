/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** two_list.c
*/

#include "../includes/intersection.h"

// main / [first, mid, end] line /

int first_line(is_t is)
{
    if(is.opt > 0 && is.opt < 4) {
        if (is.opt == 1)
            printf("Sphere of radius %i\n", is.r_a);
        if (is.opt == 2)
            printf("Cylinder of radius %i\n", is.r_a);
        if (is.opt == 3)
            printf("Cone with a %i degree angle\n", is.r_a);
        return 0;
    }
    exit(84);
}

int mid_line(is_t is)
{
    printf("Line passing through the point ");
    printf("(%.0f, %.0f, %.0f)", is.p[0], is.p[1], is.p[2]);
    printf(" and parallel to the vector ");
    printf("(%.0f, %.0f, %.0f)\n", is.v[0], is.v[1], is.v[2]);
    return 0;
}

int end_line(is_t is)
{
    if(is.nb == 0)
        printf("No intersection point.\n");

    if(is.nb == 1) {
        printf("1 intersection point:\n", is.nb);
        printf("(%.3f, %.3f, %.3f)\n", is.xyz1[0], is.xyz1[1], is.xyz1[2]);
    }

    if(is.nb == 2) {
        printf("2 intersection points:\n", is.nb);
        printf("(%.3f, %.3f, %.3f)\n", is.xyz1[0], is.xyz1[1], is.xyz1[2]);
        printf("(%.3f, %.3f, %.3f)\n", is.xyz2[0], is.xyz2[1], is.xyz2[2]);
    }
    return(0);
}

int main(int ac, char **av)
{
    is_t is;

    my_error(ac, av);
    is = init(ac, av);
    first_line(is);
    mid_line(is);
    is = calcul(is);
    end_line(is);
    return 0;
}