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

Test(Init_exit_zero, Init, .init = redirect_all_std)
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
    list_t *list = malloc( sizeof(list_t) * (ac - 1));
    cr_assert_eq(init(list, ac, av), 0);

    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
}

Test(list_egal_NULL, Init, .init = redirect_all_std)
{
    int ac = 5;
    char **av;
    list_t *list = NULL;
    cr_assert_eq(init(list, ac, av), 84);
}

Test(list_init_tab, Init, .init = redirect_all_std)
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
    list_t *list = malloc( sizeof(list_t) * (ac - 1));
    cr_assert_eq(init(list, ac, av), 0);
    cr_assert_str_eq(list[0].tab[0], "0");
    cr_assert_str_eq(list[0].tab[1], "0");
    cr_assert_str_eq(list[0].tab[2], "9");
    cr_assert_str_eq(list[1].tab[0], "1");
    cr_assert_str_eq(list[1].tab[1], "3");
    cr_assert_str_eq(list[1].tab[2], "5");
    cr_assert_str_eq(list[2].tab[0], "2");
    cr_assert_str_eq(list[2].tab[1], "4");
    cr_assert_str_eq(list[2].tab[2], "6");
    cr_assert_str_eq(list[3].tab[0], "8");
    cr_assert_str_eq(list[3].tab[1], "8");
    cr_assert_str_eq(list[3].tab[2], "8");
    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
    for (int i = 0; i < (ac - 1);i += 1) {
        for (int j = 0; j < list[i].len ;j += 1)
            if (!list[i].tab[j])
                free(list[i].tab[j]);
        if (!list[i].number)
            free(list[i].number);
        if (!list[i].tab)
            free(list[i].tab);
    }
    free(list);
}

Test(list_init_len, Init, .init = redirect_all_std)
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
    list_t *list = malloc( sizeof(list_t) * (ac - 1));
    cr_assert_eq(init(list, ac, av), 0);
    cr_assert_eq(list[0].len, 3);
    cr_assert_eq(list[1].len, 3);
    cr_assert_eq(list[2].len, 3);
    cr_assert_eq(list[3].len, 3);
    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
    for (int i = 0; i < (ac - 1);i += 1) {
        for (int j = 0; j < list[i].len ;j += 1)
            if (!list[i].tab[j])
                free(list[i].tab[j]);
        if (!list[i].number)
            free(list[i].number);
        if (!list[i].tab)
            free(list[i].tab);
    }
    free(list);
}

Test(list_init_number, Init, .init = redirect_all_std)
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
    list_t *list = malloc( sizeof(list_t) * (ac - 1));
    cr_assert_eq(init(list, ac, av), 0);
    cr_assert_eq(list[0].number[0], 0);
    cr_assert_eq(list[0].number[1], 0);
    cr_assert_eq(list[0].number[2], 9);
    cr_assert_eq(list[1].number[0], 1);
    cr_assert_eq(list[1].number[1], 3);
    cr_assert_eq(list[1].number[2], 5);
    cr_assert_eq(list[2].number[0], 2);
    cr_assert_eq(list[2].number[1], 4);
    cr_assert_eq(list[2].number[2], 6);
    cr_assert_eq(list[3].number[0], 8);
    cr_assert_eq(list[3].number[1], 8);
    cr_assert_eq(list[3].number[2], 8);
    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
    for (int i = 0; i < (ac - 1);i += 1) {
        for (int j = 0; j < list[i].len ;j += 1)
            if (!list[i].tab[j])
                free(list[i].tab[j]);
        if (!list[i].number)
            free(list[i].number);
        if (!list[i].tab)
            free(list[i].tab);
    }
    free(list);
}

Test(list_init_div_zero, Init, .init = redirect_all_std)
{
    int ac = 5;
    char **av = malloc(sizeof(char *) * ac);
    av[0] = malloc(sizeof(char) * 13);
    for (int i = 1; i < ac; i += 1)
        av[i] = malloc(sizeof(char) * ac);
    const char *av0 = "./107transfer";
    const char *av1 = "0*0*9";
    const char *av2 = "0*3*5";
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
    list_t *list = malloc( sizeof(list_t) * (ac - 1));
    cr_assert_eq(init(list, ac, av), 84);
    for (int i = 0; i < ac;i += 1)
        free(av[i]);
    free(av);
    for (int i = 0; i < (ac - 1);i += 1) {
        for (int j = 0; j < list[i].len ;j += 1)
            if (!list[i].tab[j])
                free(list[i].tab[j]);
        if (!list[i].number)
            free(list[i].number);
        if (!list[i].tab)
            free(list[i].tab);
    }
    free(list);
}