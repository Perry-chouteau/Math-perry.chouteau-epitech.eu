/*
** EPITECH PROJECT, 2020
** my str is num
** File description:
** say if the string is a number
*/

#include "../includes/my.h"

int my_str_isnum(char const *str)
{
    int	i;

    for (i = 0; str[i]; i += 1)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '.')
            return 0;
    return 1;
}

/*int main(int ac, char **av)
{
    printf("%i", my_str_isnum(av[0]));
    printf("%i", my_str_isnum(av[1])); 
    printf("%i", my_str_isnum(av[2]));
    printf("%i", my_str_isnum(av[3])); 
    printf("%i", my_str_isnum(av[4]));
    printf("%i", my_str_isnum(av[5])); 
    printf("%i", my_str_isnum(av[6]));
    printf("%i", my_str_isnum(av[7])); 
}*/