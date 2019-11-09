/*
** EPITECH PROJECT, 2019
** Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int disp_stdarg(char *, ...);
int sum_stdarg(int i, int nb, ...);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sum_stdarg, sum_of_positive)
{
    cr_assert_eq(sum_stdarg(0, 1, 13), 13);
    cr_assert_eq(sum_stdarg(0, 5, 6, 14, 89, 42, 69), 220);
    cr_assert_eq(sum_stdarg(0, 7, 7, 5, 3, 1, 9, 13, 4), 42);
    cr_assert_eq(sum_stdarg(0, 6, 13, 17, 9, 5, 11, 14), 69);
}

Test(sum_stdarg, sum_of_negative)
{
    cr_assert_eq(sum_stdarg(0, 1, -13), -13);
    cr_assert_eq(sum_stdarg(0, 5, -6, -14, -89, -42, -69), -220);
    cr_assert_eq(sum_stdarg(0, 7, -7, -5, -3, -1, -9, -13, -4), -42);
    cr_assert_eq(sum_stdarg(0, 6, -13, -17, -9, -5, -11, -14), -69);
}

Test(sum_stdarg, sum_of_relative)
{
    cr_assert_eq(sum_stdarg(0, 5, 6, 14, -89, -42, 69), -42);
    cr_assert_eq(sum_stdarg(0, 7, 7, -5, -3, -1, 9, -13, 4), -2);
    cr_assert_eq(sum_stdarg(0, 6, -13, 17, 9, -5, 11, -14), 5);
}

Test(sum_stdarg, sum_size_of_one_str)
{
    cr_assert_eq(sum_stdarg(1, 1, "Hello from EPITECH, people are working."), 39);
    cr_assert_eq(sum_stdarg(1, 3, "Hello", "World", "EPITECH"), 17);
    cr_assert_eq(sum_stdarg(1, 4, "Byte", "Je", "How you doing", "Here is the program"), 38);
    cr_assert_eq(sum_stdarg(1, 2, "So it is how it is.", "well done!"), 29);
}

Test(disp_stdarg, disp_one_int, .init=redirect_all_stdout)
{
    disp_stdarg("i", 42);
    cr_assert_stdout_eq_str("42\n");
}

Test(disp_stdarg, disp_many_int, .init=redirect_all_stdout)
{
    disp_stdarg("iiii", 42, 69, 17, 31);
    cr_assert_stdout_eq_str("42\n69\n17\n31\n");
}

Test(disp_stdarg, disp_one_char, .init=redirect_all_stdout)
{
    disp_stdarg("c", 'a');
    cr_assert_stdout_eq_str("a\n");
}

Test(disp_stdarg, disp_many_char, .init=redirect_all_stdout)
{
    disp_stdarg("ccccccc", 'E', 'P', 'I', 'T', 'E', 'C', 'H');
    cr_assert_stdout_eq_str("E\nP\nI\nT\nE\nC\nH\n");
}

Test(disp_stdarg, disp_one_str, .init=redirect_all_stdout)
{
    disp_stdarg("s", "EPITECH");
    cr_assert_stdout_eq_str("EPITECH\n");
}

Test(disp_stdarg, disp_many_str, .init=redirect_all_stdout)
{
    disp_stdarg("ssss", "Work", "Hello", "World", "printf life");
    cr_assert_stdout_eq_str("Work\nHello\nWorld\nprintf life\n");
}

Test(disp_stdarg, disp_once_each_var, .init=redirect_all_stdout)
{
    disp_stdarg("ics", 42, 'E', "Computer");
    cr_assert_stdout_eq_str("42\nE\nComputer\n");
}

Test(disp_stdarg, disp_manytimes_each_var, .init=redirect_all_stdout)
{
    disp_stdarg("isisccccccc", 69, "Well,", 42, "is worse than", 'E', 'P', 'I', 'T', 'E', 'C', 'H');
    cr_assert_stdout_eq_str("69\nWell,\n42\nis worse than\nE\nP\nI\nT\nE\nC\nH\n");
}