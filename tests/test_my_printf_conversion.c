/*
** EPITECH PROJECT, 2019
** Test my_printf()
** File description:
** Test a function
*/

#include <my_printf.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_printf, handle_o_flag)
{
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("%o", 16);
    cr_expect_stdout_eq_str("20");
    cr_expect_eq(n, 2);
}

Test(my_printf, handle_u_flag)
{
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("%u", 321654);
    cr_expect_stdout_eq_str("321654");
    cr_expect_eq(n, 6);
}

Test(my_printf, handle_x_flag)
{
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("%x", 3135);
    cr_expect_stdout_eq_str("c3f");
    cr_expect_eq(n, 3);
}

Test(my_printf, handle_X_flag)
{
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("%X", 0);
    cr_expect_stdout_eq_str("0");
    cr_expect_eq(n, 1);
}

Test(my_printf, handle_b_flag)
{
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("%b", 255);
    cr_expect_stdout_eq_str("11111111");
    cr_expect_eq(n, 8);
}

Test(my_printf, handle_S_flag)
{
    char str[] = "test";
    int n = 0;

    str[1] = 10;
    cr_redirect_stdout();
    n = my_printf("%S", str);
    cr_expect_stdout_eq_str("t\\012st");
    cr_expect_eq(n, 7);
}
