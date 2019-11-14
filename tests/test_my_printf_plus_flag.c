/*
** EPITECH PROJECT, 2019
** Test my_printf()
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, plus_flag_with_positive_number)
{
    cr_redirect_stdout();
    my_printf("%+d", 6);
    cr_expect_stdout_eq_str("+6");
}

Test(my_printf, plus_flag_with_negative_number)
{
    cr_redirect_stdout();
    my_printf("%+i", -15);
    cr_expect_stdout_eq_str("-15");
}

Test(my_printf, plus_flag_blank_padding)
{
    cr_redirect_stdout();
    my_printf("%+4d", 6);
    cr_expect_stdout_eq_str("  +6");
}

Test(my_printf, plus_flag_zero_padding)
{
    cr_redirect_stdout();
    my_printf("%0+4d", 6);
    cr_expect_stdout_eq_str("+006");
}