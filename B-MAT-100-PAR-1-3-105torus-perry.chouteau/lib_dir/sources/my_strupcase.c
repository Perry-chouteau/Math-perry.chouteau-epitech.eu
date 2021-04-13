/*
** EPITECH PROJECT, 2020
** my strupcase
** File description:
** The STRUPCASE function returns a copy of String converted to upper case.
*/

#include "../includes/my.h"

char *my_strupcase(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - ('a' - 'A');
    }
    return str;
}

