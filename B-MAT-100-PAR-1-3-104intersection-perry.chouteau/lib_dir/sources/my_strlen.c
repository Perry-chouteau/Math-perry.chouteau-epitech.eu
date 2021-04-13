/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** my_strlen.c
*/

#include "../includes/my.h"

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i += 1);
    return i;
}
