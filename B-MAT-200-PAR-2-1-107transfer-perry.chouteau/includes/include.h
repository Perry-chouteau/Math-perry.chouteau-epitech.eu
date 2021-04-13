/*
** EPITECH PROJECT, 2020
** Psu2
** File description:
** navy.h
*/

#ifndef ITSC_H
#define ITSC_H

//lib - lib_c
#include "../libmy/includes/my.h"
#include <stdlib.h>
#include <string.h>

//write
#include <unistd.h>
#include <stdio.h>

//math
#include <math.h>

//signal
#include <signal.h>
#include <stddef.h>

// sys & bits
#include <sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

//criterion
#include <criterion/criterion.h>

//struct
typedef struct list_s
{
    char **tab;
    int *number;
    int len;
}list_t;

// error / -h / init
int my_error(int ac, char **av);
int init(list_t *list, int ac, char **av);
char **my_str_to_word_array(const char *str, const char key);
int my_strlen(const char *str);
int transfer(list_t *list, int ac);
int describe(void);

#endif