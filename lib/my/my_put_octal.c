/*
** EPITECH PROJECT, 2019
** my_put_octal
** File description:
** displays the number given in octal base
*/

#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void my_putstr(char *);

void my_put_octal(uint64_t nb)
{
    int i = 0;
    int j = 0;
    uint64_t octal_pow = 1;
    char *octal_nb;

    for (; (octal_pow * 8) <= nb; i++)
        octal_pow *= 8;
    octal_nb = malloc(sizeof(char) * (i + 2));
    for (; j <= i; j++)
        octal_nb[j] = '0';
    j = 0;
    while (j <= i) {
        if (nb >= octal_pow) {
            nb -= octal_pow;
            octal_nb[j] += 1;
        } else {
            octal_pow /= 8;
            j++;
        }
    }
    octal_nb[j] = '\0';
    my_putstr(octal_nb);
    free(octal_nb);
}