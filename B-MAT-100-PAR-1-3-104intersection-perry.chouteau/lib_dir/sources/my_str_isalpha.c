/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** my_str_isalpha.c
*/

#include "../includes/my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            i += 1;
        else
            return (0);
    }
    return (1);
}