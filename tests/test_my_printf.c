/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** tests
*/

#define _GNU_SOURCE
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

void my_printf(char *, ...);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf, prints_int_i, .init=redirect_all_stdout)
{
    my_printf("%i\n%i\n%i\n%i\n", 42, 69, -2147483648, 2147483647);
    cr_assert_stdout_eq_str("42\n69\n-2147483648\n2147483647\n");
}

Test (my_printf, prints_int_d, .init=redirect_all_stdout)
{
    my_printf("%d\n%d\n%d\n%d\n", 22, 54, -2147483648, 2147483647);
    cr_assert_stdout_eq_str("22\n54\n-2147483648\n2147483647\n");
}

Test (my_printf, prints_octal, .init=redirect_all_stdout)
{
    my_printf("%o\n%o\n%o\n", 22, 54, 2147483647);
    cr_assert_stdout_eq_str("26\n66\n17777777777\n");
}

Test (my_printf, prints_uint, .init=redirect_all_stdout)
{
    my_printf("%u\n%u\n%u\n%u\n", 42, 69, 2147483647, 4294967295);
    cr_assert_stdout_eq_str("42\n69\n2147483647\n4294967295\n");
}

Test (my_printf, prints_hexa_min, .init=redirect_all_stdout)
{
    my_printf("%x\n%x\n%x\n%x\n", 42, 69, 2147483647, 4294967295);
    cr_assert_stdout_eq_str("2a\n45\n7fffffff\nffffffff\n");
}

Test (my_printf, prints_hexa_maj, .init=redirect_all_stdout)
{
    my_printf("%X\n%X\n%X\n%X\n", 42, 69, 2147483647, 4294967295);
    cr_assert_stdout_eq_str("2A\n45\n7FFFFFFF\nFFFFFFFF\n");
}

Test (my_printf, prints_str, .init=redirect_all_stdout)
{
    my_printf("This is %s, it is %s\n", "Marvin", "The Moulinette");
    cr_assert_stdout_eq_str("This is Marvin, it is The Moulinette\n");
}

Test (my_printf, prints_adress, .init=redirect_all_stdout)
{
    char *str = "Hello World";
    char *strp;

    asprintf(&strp, "%p\n", str);
    my_printf("%p\n", str);
    cr_assert_stdout_eq_str(strp);
    free(strp);
}

Test (my_printf, prints_long, .init=redirect_all_stdout)
{
    my_printf("%l\n%l\n%l\n%l\n", 42, 69, 9223372036854775807, -9223372036854775807);
    cr_assert_stdout_eq_str("42\n69\n9223372036854775807\n-9223372036854775807\n");
}

Test (my_printf, prints_long_long, .init=redirect_all_stdout)
{
    my_printf("%ll\n%ll\n%ll\n%ll\n", 42, 69, 9223372036854775807, -9223372036854775807);
    cr_assert_stdout_eq_str("42\n69\n9223372036854775807\n-9223372036854775807\n");
}

Test (my_printf, prints_long_long_q, .init=redirect_all_stdout)
{
    my_printf("%q\n%q\n%q\n%q\n", 42, 69, 9223372036854775807, -9223372036854775807);
    cr_assert_stdout_eq_str("42\n69\n9223372036854775807\n-9223372036854775807\n");
}

Test (my_printf, prints_binary, .init=redirect_all_stdout)
{
    my_printf("%b\n%b\n%b\n%b\n", 42, 69, 15, 111);
    cr_assert_stdout_eq_str("101010\n1000101\n1111\n1101111\n");
}

Test (my_printf, prints_unprintable, .init=redirect_all_stdout)
{
    char *str = malloc(sizeof(char) * 6);

    str[0] = 7;
    str[1] = 31;
    str[2] = 127;
    str[3] = 12;
    str[4] = 24;
    str[5] = '\0';
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("\\007\\037\\177\\014\\030\n");
    free(str);
}