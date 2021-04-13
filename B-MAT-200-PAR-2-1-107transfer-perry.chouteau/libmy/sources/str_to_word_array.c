/*
** EPITECH PROJECT, 2020
** B-MAT-200-PAR-2-1-107transfer-perry.chouteau
** File description:
** str_to_word_array.c
*/

#include <unistd.h>
#include <stdlib.h>

char **my_str_to_word_array(const char *str,const char key)
{
    char **tab;
    int y = 1;
    int tmp = 0;

    for (int i = 0; str[i]; i += 1)
        if (str[i] == key)
            y += 1;
    tab = malloc(sizeof(char *) * (y + 1));
    tab[y] = NULL;
    for (int i = 0; i < y; i += 1) {
        int x = 0;
        for (int j = 0; str[tmp + j] != key && str[tmp + j] != '\0'; j += 1)
            x += 1;
        tab[i] = malloc(sizeof(char) * x + 1);
        tab[i][x] = '\0';
        for (int j = 0; j < x; j += 1)
            tab[i][j] = str[tmp + j];
        tmp += (x + 1);
    }
    return tab;
}