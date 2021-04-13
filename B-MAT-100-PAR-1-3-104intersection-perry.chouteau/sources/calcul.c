/*
** EPITECH PROJECT, 2020
** B-MAT-100-PAR-1-3-104intersection-perry.chouteau
** File description:
** calcul.c
*/

#include "../includes/intersection.h"
is_t find_abc(is_t is)
{
    if (is.opt == 1)
        is.abc = intersection_sphere(is.p , is.v, is.r_a);
    if (is.opt == 2)
        is.abc = intersection_cylindre(is.p , is.v, is.r_a);
    if (is.opt == 3)
        is.abc = intersection_cone(is.p , is.v, is.r_a);
    return is;
}

is_t find_xyz(is_t is)
{
    if (is.nb >= 1)
        is.xyz1 = def_line_pos(is.p, is.v, is.t[0]);
    if (is.nb == 2)
        is.xyz2 = def_line_pos(is.p, is.v, is.t[1]);
    return is;
}

is_t calcul(is_t is)
{
    is = find_abc(is);
    is.nb = equadra_nb_solut(is.abc[0], is.abc[1], is.abc[2]);
    is.t = equadra_solut(is.abc[0], is.abc[1], is.abc[2]);
    is = find_xyz(is);
    return is;
}