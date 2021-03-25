/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** swap two number
*/

#include "../includes/my.h"
#include<stdio.h>

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
