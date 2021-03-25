/*
** EPITECH PROJECT, 2020
** my strlowcase
** File description:
** The STRLOWCASE function returns a copy of String
** converted to lowercase characters.
*/

#include "../includes/my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_strlowcase(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + ('a' - 'A');
    }
    return str;
}
