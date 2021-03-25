/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** two_ltt.c
*/

#include "../includes/torus.h"

// main / [first, mid, end] line /

void describe(void)
{
    my_printf("USAGE\n");
    my_printf("\t./105torus opt a0 a1 a2 a3 a4 n\n");
    my_printf("\n");
    my_printf("DESCRIPTION\n");
    my_printf("\topt\tmethod option:\n");
    my_printf("\t\t1 for the bisection method\n");
    my_printf("\t\t2 for Newton’s method\n");
    my_printf("\t\t3 for the secant method\n");
    my_printf("\ta[0-4]\tcoefficients of the equation\n");
    my_printf("\tn\tprecision (the application of the polynomial \
to the solution should\n");
    my_printf("\t\tbe smaller than 10ˆ-n)\n");
    return ;
}

int my_error(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0 &&   \
    my_strlen(av[1]) == 2) {
        describe();
        return 1;
    }
    if (ac != 8)
        return 84;
    for (int i = 1; i < ac; i += 1)
        if (my_str_isnum(av[i]) == 0)
            return 84;
    if (atof(av[1]) != 1 && atof(av[1]) != 2 && atof(av[1]) != 3)
        return 84;
    if (atof(av[7]) <= 0 || atof(av[7]) > 15)
        return 84;
    return 0;
}

torus_t init(int ac, char **av)
{
    torus_t areturn;
    areturn.opt = my_getnbr(av[1]);
    areturn.a = malloc(sizeof(double) * 5);
    for (int i = 0; i < 5; i += 1)
        areturn.a[i] = atof(av[2 + i]);
    areturn.n = atoi(av[7]);
    return areturn;
}

int torus(torus_t tor)
{
    if (tor.opt == 1)
        return (bisection(tor));
    if (tor.opt == 2)
        return (newton(tor));
    if (tor.opt == 3)
        return (secant(tor));
    return 84;
}

int main(int ac, char **av)
{
    torus_t tor;

    if (my_error(ac, av) == 1)
        return 0;
    else if (my_error(ac, av) == 84)
        return 84;
    tor = init(ac, av);
    return (torus(tor));
}