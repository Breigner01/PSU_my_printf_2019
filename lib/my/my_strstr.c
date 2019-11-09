/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** looks for a substring in the string
*/

#include <stddef.h>

int my_strlen(char const *str);
int *compare(char *, char const *, int *);

char *my_strstr(char *str, char const *to_find)
{
    int i[3] = {0, 0, 0};
    int len = my_strlen(to_find);

    while (str[i[0]] != '\0') {
        compare(str, to_find, i);
        if (i[2] == 1)
            return (str + i[0] - i[1]);
        if (i[2] == 2)
            return (NULL);
        i[0] -= i[1];
        i[1] = 0;
        i[0]++;
    }
    return (NULL);
}

int *compare(char *str, char const *to_find, int *i)
{
    while (str[i[0]] == to_find[i[1]] || to_find[i[1]] == '\0') {
        if (to_find[i[1]] == '\0') {
            i[2] = 1;
            return (i);
        }
        i[0]++;
        i[1]++;
        if (str[i[0]] == '\0' && to_find[i[1]] != '\0') {
            i[2] = 2;
            return (i);
        }
    }
}
