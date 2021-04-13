/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** find and return a sub-string into a string up to the end
*/

#include "../includes/my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j;
    char *str1;

    while (str[i] != '\0')
    {
        i += 1;
        j = 0;
        if (str[i] == str[j] && str[j] != '\0')
        {
            i = i + 1;
            str1 = &str[1];
            if (str[i] == str[j] && str[j] != '\0')
            {
                j += 1;
                return (str1);
            }
            i += 1;
        }
    }
}
