/*
** EPITECH PROJECT, 2020
** B-MAT-200-PAR-2-1-107transfer-perry.chouteau
** File description:
** test_error.c
*/

#include "../includes/include.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(No_arg, Err, .init = redirect_all_std)
{ 
    int ac = 1;
    char **av;
    cr_assert_eq(my_error(ac, av), 84);
}

Test(Bad_nb_arg, Err, .init = redirect_all_std)
{
    int ac = 8;
    char **av;
    cr_assert_eq(my_error(ac, av), 84);
}

Test(Bad_arg, Err, .init = redirect_all_std)
{
    int ac = 5;
    char **av = malloc(sizeof(char *) * ac);
    av[0] = malloc(sizeof(char) * 13);
    for (int i = 1; i < ac; i += 1)
        av[i] = malloc(sizeof(char) * ac);
    const char *av0 = "./107transfer";
    const char *av1 = "-x*-0*9";
    const char *av2 = "1*3*5";
    const char *av3 = "2*4*6";
    const char *av4 = "8*8*8";
    for (int i = 0; i < strlen(av0); i += 1) 
        av[0][i] = av0[i];
    for (int i = 0; i < strlen(av1); i += 1) 
        av[1][i] = av1[i];
    for (int i = 0; i < strlen(av3); i += 1) 
        av[2][i] = av2[i];
    for (int i = 0; i < strlen(av4); i += 1) 
        av[3][i] = av3[i];
    for (int i = 0; i < strlen(av4); i += 1) 
        av[4][i] = av4[i];

    cr_assert_eq(my_error(ac, av), 84);

    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
}

Test(Help1, Err, .init = redirect_all_std)
{
    int ac = 2;
    char **av = malloc(sizeof(char *) * ac);
    av[0] = malloc(sizeof(char) * 13);
    for (int i = 1; i < ac; i += 1)
        av[i] = malloc(sizeof(char) * ac);
    const char *av0 = "./107transfer";
    const char *av1 = "-h";
    for (int i = 0; i < strlen(av0); i += 1) 
        av[0][i] = av0[i];
    for (int i = 0; i < strlen(av1); i += 1) 
        av[1][i] = av1[i];
    cr_assert_eq(my_error(ac, av), 1);
    cr_assert_eq(describe(), 1);
    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
}

Test(Help2, Err, .init = redirect_all_std)
{
    int ac = 2;
    char **av = malloc(sizeof(char *) * ac);
    av[0] = malloc(sizeof(char) * 13);
    for (int i = 1; i < ac; i += 1)
        av[i] = malloc(sizeof(char) * ac);
    const char *av0 = "./107transfer";
    const char *av1 = "-t";
    for (int i = 0; i < strlen(av0); i += 1) 
        av[0][i] = av0[i];
    for (int i = 0; i < strlen(av1); i += 1) 
        av[1][i] = av1[i];
    cr_assert_eq(my_error(ac, av), 84);
    cr_assert_eq(describe(), 1);
    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
}

Test(Test1, Err, .init = redirect_all_std)
{
    int ac = 5;
    char **av = malloc(sizeof(char *) * ac);
    av[0] = malloc(sizeof(char) * 13);
    for (int i = 1; i < ac; i += 1)
        av[i] = malloc(sizeof(char) * ac);
    const char *av0 = "./107transfer";
    const char *av1 = "0*0*9";
    const char *av2 = "1*3*5";
    const char *av3 = "2*4*6";
    const char *av4 = "8*8*8";
    for (int i = 0; i < strlen(av0); i += 1) 
        av[0][i] = av0[i];
    for (int i = 0; i < strlen(av1); i += 1) 
        av[1][i] = av1[i];
    for (int i = 0; i < strlen(av3); i += 1) 
        av[2][i] = av2[i];
    for (int i = 0; i < strlen(av4); i += 1) 
        av[3][i] = av3[i];
    for (int i = 0; i < strlen(av4); i += 1) 
        av[4][i] = av4[i];
    cr_assert_eq(my_error(ac, av), 0);
    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
}
