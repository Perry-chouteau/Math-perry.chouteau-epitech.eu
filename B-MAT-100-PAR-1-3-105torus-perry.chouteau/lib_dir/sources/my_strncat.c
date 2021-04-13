/*
** EPITECH PROJECT, 2020
** my str cat
** File description:
** my str cat
*/

#include "../includes/my.h"

char *my_strncat(char *dest, char *src, int nb)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0' && j < nb)
        dest[i += 1] = src[j += 1];
    dest[i] = '\0';
    return (dest);
}