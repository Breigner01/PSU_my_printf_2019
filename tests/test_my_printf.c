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

TestSuite(my_printf, .init=redirect_all_stdout, .timeout=2);

Test (my_printf, prints_int_i)
{
    char *str;

    asprintf(&str, "%i\n%i\n%i\n%i\n", 42, 69, -2147483648, 2147483647);
    my_printf("%i\n%i\n%i\n%i\n", 42, 69, -2147483648, 2147483647);
    cr_assert_stdout_eq_str(str, "Got [%s]\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_int_d)
{
    char *str;

    asprintf(&str, "%d\n%d\n%d\n%d\n", 22, 54, -2147483648, 2147483647);
    my_printf("%d\n%d\n%d\n%d\n", 22, 54, -2147483648, 2147483647);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected[%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_octal)
{
    char *str;

    asprintf(&str, "%o\n%o\n%o\n", 22, 54, 2147483647);
    my_printf("%o\n%o\n%o\n", 22, 54, 2147483647);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected[%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_uint)
{
    char *str;

    asprintf(&str, "%u\n%u\n%u\n%u\n", 42, 69, 2147483647, 4294967295);
    my_printf("%u\n%u\n%u\n%u\n", 42, 69, 2147483647, 4294967295);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected[%s].\n");
    free(str);
}

Test (my_printf, prints_hexa_min)
{
    char *str;

    asprintf(&str, "%x\n%x\n%x\n%x\n", 42, 69, 2147483647, 4294967295);
    my_printf("%x\n%x\n%x\n%x\n", 42, 69, 2147483647, 4294967295);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_hexa_maj)
{
    char *str;

    asprintf(&str, "%X\n%X\n%X\n%X\n", 42, 69, 2147483647, 4294967295);
    my_printf("%X\n%X\n%X\n%X\n", 42, 69, 2147483647, 4294967295);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_str)
{
    char *str;

    asprintf(&str, "This is %s, it is %s\n", "Marvin", "The Moulinette");
    my_printf("This is %s, it is %s\n", "Marvin", "The Moulinette");
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_adress)
{
    char *str = malloc(sizeof(char) * 12);
    char *strp;

    str = "Hello World!";
    asprintf(&strp, "%p\n", str);
    my_printf("%p\n", str);
    cr_assert_stdout_eq_str(strp, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, strp);
    free(str);
    free(strp);
}

Test (my_printf, prints_long)
{
    char *str;

    asprintf(&str, "%ld\n%ld\n%ld\n%ld\n", 42, 69, 9223372036854775807, -9223372036854775807);
    my_printf("%l\n%l\n%l\n%l\n", 42, 69, 9223372036854775807, -9223372036854775807);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_long_long)
{
    char *str;

    asprintf(&str, "%lld\n%lld\n%lld\n%lld\n", 42, 69, 9223372036854775807, -9223372036854775807);
    my_printf("%ll\n%ll\n%ll\n%ll\n", 42, 69, 9223372036854775807, -9223372036854775807);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_long_long_q)
{
    char *str;

    asprintf(&str, "%qd\n%qd\n%qd\n%qd\n", 42, 69, 9223372036854775807, -9223372036854775807);
    my_printf("%q\n%q\n%q\n%q\n", 42, 69, 9223372036854775807, -9223372036854775807);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_binary)
{
    char *str;

    asprintf(&str, "101010\n1000101\n1111\n1101111\n");
    my_printf("%b\n%b\n%b\n%b\n", 42, 69, 15, 111);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_unprintable)
{
    char *str = malloc(sizeof(char) * 6);
    char *string;

    str[0] = 7;
    str[1] = 31;
    str[2] = 127;
    str[3] = 12;
    str[4] = 24;
    str[5] = '\0';
    asprintf(&string, "\\007\\037\\177\\014\\030\n");
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str(string, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, string);
    free(string);
    free(str);
}

Test (my_printf, prints_longd)
{
    char *str;

    asprintf(&str, "%ld\n%ld\n%ld\n%ld\n", 42, 69, 9223372036854775807, -9223372036854775807);
    my_printf("%ld\n%ld\n%ld\n%ld\n", 42, 69, 9223372036854775807, -9223372036854775807);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_longi)
{
    char *str;

    asprintf(&str, "%li\n%li\n%li\n%li\n", 42, 69, 9223372036854775807, -9223372036854775807);
    my_printf("%li\n%li\n%li\n%li\n", 42, 69, 9223372036854775807, -9223372036854775807);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_long_octal)
{
    char *str;

    asprintf(&str, "%lo\n%lo\n%lo\n", 42, 69, 123456789);
    my_printf("%lo\n%lo\n%lo\n", 42, 69, 123456789);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_long_hexa_min)
{
    char *str;

    asprintf(&str, "%lx\n%lx\n%lx\n", 42, 69, 123456789);
    my_printf("%lx\n%lx\n%lx\n", 42, 69, 123456789);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}

Test (my_printf, prints_long_hexa_maj)
{
    char *str;

    asprintf(&str, "%lX\n%lX\n%lX\n", 42, 69, 123456789);
    my_printf("%lX\n%lX\n%lX\n", 42, 69, 123456789);
    cr_assert_stdout_eq_str(str, "Got [%s].\nBut expected [%s].\n", cr_redirect_stdout, str);
    free(str);
}