/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-bs103cipher-perry.chouteau
** File description:
** key.c
*/

#include "../includes/cipher.h"

cphr_t mk_msg_mtrx(cphr_t cphr)
{
    int k = 0;

    if (cphr.ac < 3 || cphr.ac > 3)
        exit(84);
    cphr.mtrx.i.msg = malloc(sizeof(int *) * cphr.mtrx.n.row);
    for (int i = 0; i < cphr.mtrx.n.row; i += 1)
        cphr.mtrx.i.msg[i] = malloc(sizeof(int) * cphr.mtrx.n.col);
    for (int i = 0; i < cphr.mtrx.n.row; i += 1)
        for (int j = 0; j < cphr.mtrx.n.col; j += 1, k += 1) {
            if (k < cphr.mtrx.sz.msg)
                cphr.mtrx.i.msg[i][j] = cphr.av[1][k];
            else
                cphr.mtrx.i.msg[i][j] = 0;
        }
    return cphr;
}

cphr_t mk_key_mtrx(cphr_t cphr)
{
    int k = 0;

    if (cphr.ac < 3 || cphr.ac > 3)
        exit(84);
    cphr.mtrx.i.key = malloc(sizeof(int *) * cphr.mtrx.n.col);
    for (int i = 0; i < cphr.mtrx.n.col; i += 1)
        cphr.mtrx.i.key[i] = malloc(sizeof(int) * cphr.mtrx.n.col);
    for (int i = 0; i < cphr.mtrx.n.col; i += 1)
        for (int j = 0; j < cphr.mtrx.n.col; j += 1, k += 1) {
            if (k < cphr.mtrx.sz.key)
                cphr.mtrx.i.key[i][j] = cphr.av[2][k];
            else
                cphr.mtrx.i.key[i][j] = 0;
            }
    return cphr;
}

cphr_t mk_code(cphr_t cphr)
{
    int k = 0;

    cphr.mtrx.c.msg = malloc(sizeof(int *) * cphr.mtrx.n.row);
    for (int i = 0; i < cphr.mtrx.n.row; i += 1)
        cphr.mtrx.c.msg[i] = malloc(sizeof(int) * cphr.mtrx.n.col);
    for (int i = 0; i < cphr.mtrx.n.row ; i += 1)
        for (int j = 0; j < cphr.mtrx.n.col; j += 1, k += 1) {
            cphr.mtrx.c.msg[i][j] = 0;
            for (int l = (cphr.mtrx.n.col - 1); l >= 0; l -= 1)
                cphr.mtrx.c.msg[i][j] += \
                cphr.mtrx.i.msg[i][l] * cphr.mtrx.i.key[l][j];
        }
    return cphr;
}