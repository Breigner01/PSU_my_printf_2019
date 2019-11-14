/*
** EPITECH PROJECT, 2019
** my_put_hexa
** File description:
** change a decimal number into an hexadecimal number
*/

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "my.h"

char over_ten(char c, int letter)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
        (c >= 'a' && c <= 'f'))
        return (c);
    else
        return (c + letter);
}

void my_put_hexa(uint64_t nb, int letter)
{
    int i = 0;
    int j = 0;
    uint64_t hexa_pow = 1;
    char *hexa_nb;

    for (; (hexa_pow * 16) <= nb; i++)
        hexa_pow *= 16;
    hexa_nb = malloc(sizeof(char) * (i + 2));
    for (; j <= i; j++)
        hexa_nb[j] = '0';
    j = 0;
    while (j <= i) {
        if (nb >= hexa_pow) {
            nb -= hexa_pow;
            hexa_nb[j] += 1;
            hexa_nb[j] = over_ten(hexa_nb[j], letter);
        } else {
            hexa_pow /= 16;
            j++;
        }
    }
    hexa_nb[j] = '\0';
    my_putstr(hexa_nb);
    free(hexa_nb);
}

void my_put_hexa_min(uint64_t nb)
{
    my_put_hexa(nb, 39);
}

void my_put_hexa_maj(uint64_t nb)
{
    my_put_hexa(nb, 7);
}

void my_put_address(uint64_t nb)
{
    my_putstr("0x");
    my_put_hexa(nb, 39);
}