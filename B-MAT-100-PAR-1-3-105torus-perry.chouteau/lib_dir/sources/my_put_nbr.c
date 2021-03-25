/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** write number
*/

#include "../includes/my.h"

int my_put_nbr(int nb)
{
    int begin;
    int end;

    if (nb < 0)
    {
        nb *= -1;
        my_putchar('-');
        my_put_nbr(nb);
    }
    else
    {
        end = nb % 10;
        begin = nb / 10;
        if (begin != 0)
            my_put_nbr(begin);
        my_putchar(end + '0');
    }
    return 0;
}
