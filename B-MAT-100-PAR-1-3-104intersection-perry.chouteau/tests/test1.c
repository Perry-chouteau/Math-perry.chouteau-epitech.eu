/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** test.c
*/

#include "../includes/intersection.h"

int init_test(is_t is)
{
    return 0;
}

Test (init_test, struct_ac)
{
    is_t is;

    int ac = init_test(is);
    cr_assert_eq(ac, 0);
}