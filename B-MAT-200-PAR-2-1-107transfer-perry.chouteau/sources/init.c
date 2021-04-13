/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-pushswap-perry.chouteau
** File description:
** init.c
*/

#include "../includes/include.h"

int describe(void)
{
    printf("USAGE\n");
    printf("    ./107transfer [num den]*\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("    num\t   polynomial numerator defined by its coefficients\n");
    printf("    den\t   polynomial denominator defined by its coefficients\n");
    return 1;
}

int my_str_isfine(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '*')
            return 0;
    return 1;
}

int my_error(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return describe();
    if (ac < 3)
        return 84;
    if (!(ac % 2))
        return 84;
    for (int i = 1; i < ac; i += 1)
        if (my_str_isfine(av[i]) == 0)
            return 84;
    return 0;
}

int init(list_t *list, int ac, char **av)
{
    if (!list)
        return 84;
    for (int i = 0; i < ac - 1; i += 1)
        list[i].tab = my_str_to_word_array(av[i + 1], '*');
    for (int i = 0, j; i < ac - 1; i += 1) {
        for (j = 0; list[i].tab[j];)
            j += 1;
        list[i].number = malloc(sizeof(int) * j);
        list[i].len = j;
    }
    for (int i = 0, j; i < ac - 1; i += 1) {
        for (j = 0; list[i].tab[j]; j += 1)
            list[i].number[j] = atoi(list[i].tab[j]);
    }
    for (int i = 1; i < (ac - 1); i += 2)
        if (!(list[i].number[0]))
            return 84;
    return 0;
}
