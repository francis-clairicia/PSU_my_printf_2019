/*
** EPITECH PROJECT, 2019
** Test my_printf
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, sharp_and_plus_flag)
{
    cr_redirect_stdout();
    my_printf("%#+x", 255);
    cr_expect_stdout_eq_str("0xff");
}

Test(my_printf, plus_and_minus_flag)
{
    cr_redirect_stdout();
    my_printf("%+-12d", 6);
    cr_expect_stdout_eq_str("+6          ");
}