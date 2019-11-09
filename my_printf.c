/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** act like printf
*/

#include <stdarg.h>
#include "my.h"

int my_printf(char *str, ...)
{
    int nb = 0;
    int i = 0;
    char *tab[2] = {str, "idouxXspllhhqnmb"};
    void (*fun_ptr_arr[])() = {my_put_nbr, my_put_nbr, my_put_unsigned_int,
    my_put_unsigned_int, my_put_unsigned_int, my_put_unsigned_int, my_putstr,
    my_put_hexa, my_put_long, my_put_long_long, my_put_nbr, my_putchar,
    my_put_long_long, my_writen_len, my_errno, my_put_binary};
    va_list arg;

    va_start(arg, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            flag_correspondance(tab, fun_ptr_arr, &i, arg);
        }
    }
}

void flag_correspondance(char **tab, void (*fun_ptr_arr[]), int *i, va_list arg)
{
    int j = 0;

    while (tab[0][*i] != tab[1][j] && tab[1][j] != '\0') {
        j++;
    }
    if (tab[1][j] == '\0') {
        my_putchar(tab[0][(*i) - 1]);
        my_putchar(tab[0][*i]);
    } else if ((j == 8 || j == 10) && tab[1][(*i) + 1] == tab[0][(*i) + 1])
        fun_ptr_arr[j + 1];
    else
        fun_ptr_arr[j];
}