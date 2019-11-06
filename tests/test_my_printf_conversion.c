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
    cr_redirect_stdout();
    my_printf("%o", 16);
    cr_expect_stdout_eq_str("20");
}

Test(my_printf, handle_u_flag)
{
    cr_redirect_stdout();
    my_printf("%u", 321654);
    cr_expect_stdout_eq_str("321654");
}

Test(my_printf, handle_x_flag)
{
    cr_redirect_stdout();
    my_printf("%x", 3135);
    cr_expect_stdout_eq_str("c3f");
}

Test(my_printf, handle_X_flag)
{
    cr_redirect_stdout();
    my_printf("%X", 3135);
    cr_expect_stdout_eq_str("C3F");
}

Test(my_printf, handle_b_flag)
{
    cr_redirect_stdout();
    my_printf("%b", 255);
    cr_expect_stdout_eq_str("11111111");
}

Test(my_printf, handle_S_flag)
{
    char str[] = "test";
    str[1] = 10;

    cr_redirect_stdout();
    my_printf("%S", str);
    cr_expect_stdout_eq_str("t\\012st");
}
