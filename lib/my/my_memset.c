/*
** EPITECH PROJECT, 2019
** memset
** File description:
** BISTRO
*/

#include <string.h>

void *my_memset(void *i, int j, size_t k)
{
    char* m = i;

    while (k--)
        *m++ = (unsigned char)j;
    return (i);
}
