/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** two_list.c
*/

#include "../includes/include.h"


int main(int ac, char **av)
{
    list_t *list;
    if (my_error(ac, av) == 1)
        return 0;
    if (my_error(ac, av) == 84)
        return 84;
    list = malloc(sizeof(list_t) * (ac + 1));
    if (!list)
        return 84;
    if (init(list, ac, av) == 84)
        return 84;
    transfer(list, ac);
    //free_all(list);
    return 0;
}