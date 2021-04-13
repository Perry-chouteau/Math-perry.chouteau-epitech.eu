/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-pushswap-perry.chouteau
** File description:
** equadra_lib.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "../includes/math.h"

float equadra(float a, float b, float c)
{
    return ((b * b) - (4 * a * c));
}

int equadra_nb_solut(float a, float b, float c)
{
    float d = equadra(a, b, c);

    if (d < 0)
        return 0;
    if (d == 0)
        return 1;
    if (d > 0)
        return 2;
}

float *equadra_solut(float a, float b, float c)
{
    if (a == 0)
        exit(84);
    float d = equadra(a, b, c);
    int nb = equadra_nb_solut(a, b, c);
    float *sol_s;
    if (nb == 1) {
        sol_s = malloc(sizeof(float) * 1);
        sol_s[0] = (-b /(2 * a));
    }
    if (nb == 2){
        sol_s = malloc(sizeof(float) * 2);
        sol_s[0] = (-b + sqrt(d)) / (2 * a);
        sol_s[1] = (-b - sqrt(d)) / (2 * a);
    }
    return sol_s;
}

/*|   ./intersection | [a]x^2 + [b]x, c |*/

/*int main(int ac, char **av)
{
    float a = atof(av[1]);
    float b = atof(av[2]);
    float c = atof(av[3]);
    int nb = equadra_nb_solut(a, b, c);
    float *sol_s = equadra_solut(a, b, c);

    my_printf("|>%i\t", nb);
    if (sol_s[0] == 2)
            printf("|>%f\t", sol_s[1]);
    if (sol_s[0] == 2)
            printf("|>%f\t", sol_s[2]);
    return 0;
}*/