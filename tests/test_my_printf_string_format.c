/*
** EPITECH PROJECT, 2019
** Test my_printf()
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, field_width_left_adjust)
{
    char str[] = "Test";
    char res[] = "   Test";

    cr_redirect_stdout();
    my_printf("%7s", str);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, field_width_right_adjust)
{
    char str = 'T';
    char res[] = "T           ";

    cr_redirect_stdout();
    my_printf("%-12c", str);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, field_width_zero_padded)
{
    char str[] = "72";
    char res[] = "0072";

    cr_redirect_stdout();
    my_printf("%04s", str);
    cr_expect_stdout_eq_str(res);
}