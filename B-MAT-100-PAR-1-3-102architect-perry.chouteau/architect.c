/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-102architect-perry.chouteau
** File description:
** architect.c
*/

#include "includes/102architect.h"

int main(int ac, char **av)
{
    architec_t ark;

    if (ac == 1)
        return 84;
    if (ac == 2 && av[1][0] != '-' && av[1][1] != 'h')
        return 84;
    ark = init(ac, av);
    b_test(ark);
    print_str(ark);
    return 0;
}