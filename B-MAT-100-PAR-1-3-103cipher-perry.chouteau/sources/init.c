/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-pushswap-perry.chouteau
** File description:
** init.c
*/

#include "../includes/cipher.h"

cphr_t init(int ac, char **av)
{
    cphr_t cphr;

    cphr.av = av;
    cphr.ac = (ac - 1);
    return cphr;
}

cphr_t init_key(cphr_t cphr)
{
    cphr.mtrx.sz.key = my_strlen(cphr.av[2]);
    if (cphr.mtrx.sz.key == 0)
        exit(84);
    if (cphr.mtrx.sz.key == 1)
        cphr.mtrx.n.col = 1;
    if (cphr.mtrx.sz.key > 1 && cphr.mtrx.sz.key < 5)
        cphr.mtrx.n.col = 2;
    if (cphr.mtrx.sz.key > 4 && cphr.ac < 10)
        cphr.mtrx.n.col = 3;
    if (cphr.mtrx.sz.key > 9 && cphr.ac < 17)
        cphr.mtrx.n.col = 4;
    if (cphr.mtrx.sz.key > 16)
        exit(84);
    return  cphr;
}

cphr_t init_msg(cphr_t cphr)
{
    cphr.mtrx.sz.msg = my_strlen(cphr.av[1]);
    cphr.mtrx.n.row = (cphr.mtrx.sz.msg / cphr.mtrx.n.col);
    if ((cphr.mtrx.sz.msg % cphr.mtrx.n.col) != 0)
        cphr.mtrx.n.row += 1;
    return  cphr;
}

cphr_t init_all(int ac, char **av, cphr_t cphr)
{
    cphr = init(ac, av);
    cphr = init_key(cphr);
    cphr = init_msg(cphr);
    return cphr;
}