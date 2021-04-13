/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** function that reverse a string into a array
*/

#include "../includes/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int n = 0;
    char a = 0;
    char b = 0;

    for (; str[i] != '\0'; i += 1);
    i -= 1;
    for ( n = 0; n < i; n += 1, i -= 1) {
        b = str[i];
        str[i] = str[n];
        str[n] = b ;
    }
    return str;
}
