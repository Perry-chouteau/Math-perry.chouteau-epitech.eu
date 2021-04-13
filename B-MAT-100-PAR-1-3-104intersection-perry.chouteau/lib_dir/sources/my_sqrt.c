/*
** EPITECH PROJECT, 2020
** my compute square root
** File description:
** compute square root
*/

#include "../includes/my.h"

float my_sqrt(int nb)
{
    float temp, sqrt;
    if(nb < 0)
        exit(84);
    if(nb == 0 || nb == 1)
        return nb;
    sqrt = nb / 2;
    temp = 0;
    while (sqrt != temp){
        temp = sqrt;    

        sqrt = (nb / temp + temp) / 2;
    }
    return sqrt;
}