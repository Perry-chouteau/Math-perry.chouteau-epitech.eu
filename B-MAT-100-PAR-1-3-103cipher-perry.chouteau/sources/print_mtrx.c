/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-bs103cipher-perry.chouteau
** File description:
** print_mtrx.c
*/

#include "../includes/cipher.h"

void write_key(cphr_t cphr)
{
    my_printf("Key matrix:\n");
    for (int i = 0; i < cphr.mtrx.n.col; i += 1) {
        for (int j = 0; j < cphr.mtrx.n.col; j += 1) {
            my_printf("%i", cphr.mtrx.i.key[i][j]);
            if (j < (cphr.mtrx.n.col - 1))
                my_printf("\t");
        }
        my_printf("\n");
    }
    my_printf("\n");
}

void write_code(cphr_t cphr)
{
    my_printf("Encrypted message:\n");
    for (int i = 0; i < cphr.mtrx.n.row; i += 1) {
        for (int j = 0; j < cphr.mtrx.n.col; j += 1) {
            my_printf("%i", cphr.mtrx.c.msg[i][j]);
            if (j < (cphr.mtrx.n.col - 1))
                my_printf(" ");
        }
        if (i < (cphr.mtrx.n.row - 1))
            my_printf(" ");
    }
    my_printf("\n");
}

void write_unkey(cphr_t cphr)
{
    my_printf("Key matrix:\n");
    for (int i = 0; i < cphr.mtrx.n.col; i += 1) {
        for (int j = 0; j < cphr.mtrx.n.col; j += 1) {
            my_printf("%i", cphr.unmtrx.f.key[i][j]);
            if (j < (cphr.mtrx.n.col - 1))
                my_printf("\t");
        }
        my_printf("\n");
    }
    my_printf("\n");
}

void write_msg(cphr_t cphr)
{
    my_printf("\t%cNOTHING%c\n", '"', '"');
}