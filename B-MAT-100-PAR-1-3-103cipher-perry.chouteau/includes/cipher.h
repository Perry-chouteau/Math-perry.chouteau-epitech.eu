/*
** EPITECH PROJECT, 2020
** Psu2
** File description:
** navy.h
*/

#ifndef CIPHER_H
#define CIPHER_H

#include "../printf_dir/includes/my_printf.h"
#include "../lib_dir/includes/my.h"
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <criterion/criterion.h>

typedef struct
{
    int msg;
    int key;
}sz_t;

typedef struct
{
    int col;
    int row;
}n_t;

//////////flag 0/////////////

typedef struct
{
    int **msg;
    int **key;
}i_t;

typedef struct
{
    sz_t sz;
    n_t n;
    i_t i;
    i_t c;
}mtrx_t;

//////////flag 1////////////

typedef struct
{
    int **msg;
    float **key;
}f_t;

typedef struct
{
    f_t f;
    char **s;
}unmtrx_t;

typedef struct
{
    int ac;
    char **av;
    mtrx_t mtrx;
    unmtrx_t unmtrx;
}cphr_t;

// error / -h / init
void my_error(int ac, char **av);
void describe(void);
void cipher(int ac, char **av);
cphr_t init_all(int ac, char **av, cphr_t cphr);
cphr_t init(int ac, char **av);
cphr_t init_key(cphr_t cphr);
cphr_t init_msg(cphr_t cphr);
cphr_t mk_key_mtrx(cphr_t cphr);

//flag: 0
cphr_t mk_msg_mtrx(cphr_t cphr);
cphr_t mk_code(cphr_t cphr);
void write_key(cphr_t cphr);
void write_code(cphr_t cphr);

//flag: 1
cphr_t mk_unkey(cphr_t cphr);
cphr_t dt_code(cphr_t cphr);
void write_unkey(cphr_t cphr);
void write_msg(cphr_t cphr);

#endif