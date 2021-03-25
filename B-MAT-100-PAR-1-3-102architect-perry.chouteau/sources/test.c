/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-102architect-perry.chouteau
** File description:
** test.c
*/

#include "../includes/102architect.h"

void b_test(architec_t ark)
{
    if (ark.save.cp_ac == 1)
        exit(84);
    if (ark.save.cp_ac == 2) {
        if (ark.save.cp_av[1][0] == '-' && ark.save.cp_av[1][1] == 'h') {
            describe();
            exit(0);
        }
    }
    if (ark.save.cp_ac < 5)
        exit(84);
    return ;
}

void error_info(architec_t ark)
{
    if (ark.save.cp_av[ark.save.i][0] != '-')
            exit (84);
    if (ark.save.cp_av[ark.save.i][1] != 't' &&  \
        ark.save.cp_av[ark.save.i][1] != 'z' &&  \
        ark.save.cp_av[ark.save.i][1] != 's' &&  \
        ark.save.cp_av[ark.save.i][1] != 'r')
            exit (84);
    if (ark.save.cp_av[ark.save.i][1] == 't' || 'z')
        for (int i = 0; ark.save.cp_av[ark.save.i + 1][i] != '\0'; i += 1)
            if (ark.save.cp_av[ark.save.i + 1][i] > '9' ||  \
            ark.save.cp_av[ark.save.i + 1][i] < '0' &&  \
            ark.save.cp_av[ark.save.i + 1][i] != '-' && \
            ark.save.cp_av[ark.save.i + 1][i] != '.')
                exit(84);
    return ;
}