/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-bs103cipher-perry.chouteau
** File description:
** unkey_msg.c
*/

#include "../includes/cipher.h"

cphr_t ncol_1_2(cphr_t cphr, int sv, float d)
{
    if (cphr.mtrx.n.col == 1) {
        cphr.unmtrx.f.key = malloc(sizeof(float *) * 1);
        cphr.unmtrx.f.key[0] = malloc(sizeof(float) * 1);
        cphr.unmtrx.f.key[0][0] = (d / cphr.mtrx.i.key[0][0]);
        return cphr;
    }

    if (cphr.mtrx.n.col == 2) {
        sv = cphr.mtrx.i.key[0][0];
        cphr.mtrx.i.key[0][0] = cphr.mtrx.i.key[1][1];
        cphr.mtrx.i.key[1][1] = sv;
        cphr.mtrx.i.key[0][1] *= (-1);
        cphr.mtrx.i.key[0][1] *= (-1);
        d /= (cphr.mtrx.i.key[0][0] * cphr.mtrx.i.key[1][1]) -  \
        ((-cphr.mtrx.i.key[0][1]) * (-cphr.mtrx.i.key[1][0]));
        cphr.unmtrx.f.key[0][0] = d * cphr.mtrx.i.key[0][0];
        cphr.unmtrx.f.key[0][1] = d * cphr.mtrx.i.key[0][1];
        cphr.unmtrx.f.key[1][0] = d * cphr.mtrx.i.key[1][0];
        cphr.unmtrx.f.key[1][1] = d * cphr.mtrx.i.key[1][1];
        return cphr;
    }
}

cphr_t ncol_3(cphr_t cphr, int sv, float d)
{
    if (cphr.mtrx.n.col >= 3)
        exit(84);
}

cphr_t ncol_4(cphr_t cphr, int sv, float d)
{
    if (cphr.mtrx.n.col == 4)
        exit(84);
    exit(84);
}

cphr_t mk_unkey(cphr_t cphr)
{
    float d = 1;
    int sv;
    cphr = ncol_1_2(cphr, sv, d);
    cphr =   ncol_3(cphr, sv, d);
    return cphr;
}

cphr_t dt_code(cphr_t cphr)
{
    return cphr;
}