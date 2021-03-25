/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** two_list.c
*/

#include "../includes/cipher.h"

void describe(void) {
    my_printf("USAGE\n");
    my_printf("   ./103cipher message key flag\n");
    my_printf("DESCRIPTION\n");
    my_printf("   message  a message, made of ASCII characters\n");
    my_printf("   key      the encryption key, made of ASCII characters\n");
    my_printf("   flag     0 for the message to be encrypted, 1 to be decrypted\n");
    exit(0);
}

void my_error(int ac, char ** av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        describe();
    if (ac < 4)
        exit(84);
    if (ac > 4)
        exit(84);
}

void cipher(int ac, char ** av)
{
    cphr_t cphr;

    cphr = init_all(ac, av, cphr);
    cphr = mk_key_mtrx(cphr);
    if (av[3][0] == '0' && av[3][1] == '\0') {
        cphr = mk_msg_mtrx(cphr);
        cphr = mk_code(cphr);
        write_key(cphr);
        write_code(cphr);
        return ;
    }
    if (av[3][0] == '1' && av[3][1] == '\0') {
        exit(84);
        cphr = keep_code(ac, av[1]);
        cphr = mk_unkey(cphr);
        cphr = dt_code(cphr);
        write_unkey(cphr);
        write_msg(cphr);
        return ;
    }
}

int main(int ac, char **av)
{
    cphr_t cphr;

    my_error(ac, av);
    cipher(ac, av);
    return 0;
}