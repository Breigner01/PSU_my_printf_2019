/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** displays the number given as parameter
*/

#include <stdlib.h>
#include <stdio.h>

void my_putchar(char);
void my_putstr(char *);
char *my_revstr(char *);

void disp_ulong(unsigned long nb)
{
    char *nb_str = malloc(sizeof(char) * 20);
    int i = 0;

    while (nb != 0) {
        nb_str[i] = nb % 10 + '0';
        nb /= 10;
        i++;
    }
    nb_str[i] = '\0';
    nb_str = my_revstr(nb_str);
    my_putstr(nb_str);
    free(nb_str);
}

void my_put_unsigned_long(unsigned long nb)
{
    if (nb < 10)
        my_putchar(nb + '0');
    else if (nb >= 10){
        disp_ulong(nb);
    }
}