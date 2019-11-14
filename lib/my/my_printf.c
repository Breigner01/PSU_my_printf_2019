/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** act like printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include "my.h"

void long_flags(char **tab, int *i, va_list arg)
{
    int j = 0;
    void (*lfun_ptr[])() = {};

    while (tab[0][*i] != tab[2][j] && tab[2][j]!= '\0')
        j++;
    if (tab[2][j] == '\0')
        my_put_long(va_arg(arg, int));
    else
}

void flag_correspondance(char **tab, void (*fun_ptr[])(), int *i, va_list arg)
{
    int j = 0;

    (*i)++;
    while (tab[0][*i] != tab[1][j] && tab[1][j] != '\0')
        j++;
    if (tab[1][j] == 'm') {
        my_putstr(strerror(errno));
        return;
    }
    if (tab[1][j] == '\0') {
        my_putchar(tab[0][(*i) - 1]);
        my_putchar(tab[0][*i]);
    } else if (j == 8)
        long_flags(tab, fun_ptr, i, arg);
    else
        fun_ptr[j](va_arg(arg, void *));
    (*i)++;
}

int my_printf(char *str, ...)
{
    int nb = 0;
    int i = 0;
    char *tab[3] = {str, "diouxXspllqbShh", "ldiouxX"};
    void (*fun_ptr[])() = {my_put_nbr, my_put_nbr, my_put_octal,
    my_put_unsigned_int, my_put_hexa_min, my_put_hexa_maj, my_putstr,
    my_put_address, my_put_long, my_put_long_long, my_put_long_long,
    my_put_binary, my_put_unprintable};
    va_list arg;

    va_start(arg, str);
    while (str[i] != '\0') {
        if (str[i] == '%')
            flag_correspondance(tab, fun_ptr, &i, arg);
        my_putchar(str[i]);
        i++;
    }
    va_end(arg);
}