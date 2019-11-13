/*
** EPITECH PROJECT, 2019
** Test my_printf
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, lld_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%lld", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, lli_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%lli", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, llb_flag)
{
    long nb = 223372036854775807;
    char res[] = "1100011001100100111010111100011101011110111111111111111111";

    cr_redirect_stdout();
    my_printf("%llb", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, llo_flag)
{
    long nb = 223372036854775807;
    char res[] = "14314472743536777777";

    cr_redirect_stdout();
    my_printf("%llo", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, llu_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%llu", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, llx_flag)
{
    long nb = 223372036854775807;
    char res[] = "31993af1d7bffff";

    cr_redirect_stdout();
    my_printf("%llx", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, llX_flag)
{
    long nb = 223372036854775807;
    char res[] = "31993AF1D7BFFFF";

    cr_redirect_stdout();
    my_printf("%llX", nb);
    cr_expect_stdout_eq_str(res);
}