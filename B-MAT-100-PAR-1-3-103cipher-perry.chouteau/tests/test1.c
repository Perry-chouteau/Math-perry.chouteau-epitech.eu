/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** test.c
*/

#include "../includes/cipher.h"

cphr_t init_test(cphr_t cphr)
{
    cphr.ac = 3;
    return cphr;
}

Test (cphr, index1_greater_than_index2)
{
    cphr_t cphr = init_test(cphr);

    cr_assert_eq(cphr.ac, 5);
}