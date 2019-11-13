/*
** EPITECH PROJECT, 2019
** Test my_printf()
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, ld_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%ld", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, li_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%li", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, lb_flag)
{
    long nb = 223372036854775807;
    char res[] = "1100011001100100111010111100011101011110111111111111111111";

    cr_redirect_stdout();
    my_printf("%lb", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, lo_flag)
{
    long nb = 223372036854775807;
    char res[] = "14314472743536777777";

    cr_redirect_stdout();
    my_printf("%lo", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, lu_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%lu", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, lx_flag)
{
    long nb = 223372036854775807;
    char res[] = "31993af1d7bffff";

    cr_redirect_stdout();
    my_printf("%lx", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, lX_flag)
{
    long nb = 223372036854775807;
    char res[] = "31993AF1D7BFFFF";

    cr_redirect_stdout();
    my_printf("%lX", nb);
    cr_expect_stdout_eq_str(res);
}