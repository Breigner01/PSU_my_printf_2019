#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int my_printf(char *, ...);

int main(void)
{
    char *str = "Hello World!";
    char *Str = malloc(sizeof(char) * 6);

    Str[0] = 7;
    Str[1] = 31;
    Str[2] = 127;
    Str[3] = 12;
    Str[4] = 24;
    Str[5] = '\0';
    my_printf("%i\n%i\n%i\n%i\n", 42, 69, -2147483648, 2147483647);
    my_printf("%d\n%d\n%d\n%d\n", 22, 54, -2147483648, 2147483647);
    my_printf("%o\n%o\n%o\n%o\n", 42, 22, 54, 2147483647);
    my_printf("%u\n%u\n%u\n%u\n", 42, 69, 2147483647, 4294967295);
    my_printf("%x\n%x\n%x\n%x\n", 42, 69, 2147483647, 4294967295);
    my_printf("%X\n%X\n%X\n%X\n", 42, 69, 2147483647, 4294967295);
    printf("Adress = %p\n", str);
    my_printf("Adress = %p\n", str);
    my_printf("%l\n%l\n%l\n%l\n", 42, 69, 9223372036854775807, -9223372036854775807);
    my_printf("%ll\n%ll\n%ll\n%ll\n", 42, 69, 9223372036854775807, -9223372036854775807);
    my_printf("%b\n%b\n%b\n%b\n", 42, 69, 15, 111);
    my_printf("%S\n", Str);
    free(Str);
}