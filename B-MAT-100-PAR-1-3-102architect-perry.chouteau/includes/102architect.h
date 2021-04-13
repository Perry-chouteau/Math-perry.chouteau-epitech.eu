/*
** EPITECH PROJECT, 2020
** 102architect.h
** File description:
** 102architect
*/

#ifndef ARCHITECT
#define ARCHITECT

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define RAD(x) (x / 180 * 3.1415926535)

typedef struct
{
    int i;
    int t;
    int s;
    int z;
    int r;
    int cp_ac;
    char ** cp_av;
}nb_prms_t;

typedef struct
{
    float *mxyz;
    float *val_xy;
    nb_prms_t save;
    float *res_xy;
}architec_t;

architec_t init(int ac, char **av);
void b_test(architec_t ark);
void describe(void);
void print_str(architec_t ark);
architec_t make_xyz(architec_t ark);
void write_result(architec_t ark);
void write_info(architec_t ark);
architec_t rm_zero(architec_t aretourner);
int info(architec_t ark);
void error_info(architec_t ark);
architec_t write_matrice(architec_t ark);
architec_t matrice1(architec_t ark);
architec_t matrice2(architec_t ark);

#endif