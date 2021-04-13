/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** say character of a string, one by one
*/

#include "../includes/my.h"

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return 0;
}
