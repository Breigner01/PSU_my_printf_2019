/*
** EPITECH PROJECT, 2019
** memset
** File description:
** BISTRO
*/

#include <string.h>
#include <stdlib.h>

int my_strlen(char *);

void *my_memset(void *ptr, int j, size_t k)
{
    char *temp = malloc(sizeof(char) * (my_strlen(ptr) + 1));

    for (size_t i = 0; i < k; i++)
        temp[i] = j;
    return (temp);
}
