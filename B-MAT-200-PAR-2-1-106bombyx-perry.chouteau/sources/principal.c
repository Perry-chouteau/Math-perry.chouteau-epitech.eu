/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** two_list.c
*/

#include "../includes/include.h"

int bombyx1(s_t *s)
{
    for (int i = 0; i < 100; i += 1) {
        printf("%i %.2f\n",(i + 1), s->n);
        s->n *= s->k * ((1000 - s->n) / 1000);
    }
    return 0;
}

int bombyx2(s_t *s)
{
    double save = s->n;

    for (double k = 1; k <= 4; k += 0.01) {
        s->n = save;
        for (int i = 0; i < s->l; i += 1) {
            if (i > s->k - 2)
                printf("%.2f %.2f\n", k , s->n);
            s->n = k * s->n * ((1000 - s->n) / 1000);
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    s_t *s;

    if (my_error(ac, av) == 1)
        return 0;
    if (my_error(ac, av) == 84)
        return 84;
    s = malloc(sizeof(s_t));
    init(s, ac, av);
    if (ac == 3)
        return bombyx1(s);
    if (ac == 4)
        return bombyx2(s);
    return -1;
}