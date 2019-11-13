/*
** EPITECH PROJECT, 2019
** Test my_printf()
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, sharp_o)
{
    cr_redirect_stdout();
    my_printf("%#o", 8);
    cr_expect_stdout_eq_str("010");
}

Test(my_printf, sharp_x)
{
    cr_redirect_stdout();
    my_printf("%#x", 255);
    cr_expect_stdout_eq_str("0xff");
}