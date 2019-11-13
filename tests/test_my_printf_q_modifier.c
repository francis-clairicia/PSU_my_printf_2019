/*
** EPITECH PROJECT, 2019
** Test my_printf
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, qd_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%qd", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, qi_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%qi", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, qb_flag)
{
    long nb = 223372036854775807;
    char res[] = "1100011001100100111010111100011101011110111111111111111111";

    cr_redirect_stdout();
    my_printf("%qb", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, qo_flag)
{
    long nb = 223372036854775807;
    char res[] = "14314472743536777777";

    cr_redirect_stdout();
    my_printf("%qo", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, qu_flag)
{
    long nb = 223372036854775807;
    char res[] = "223372036854775807";

    cr_redirect_stdout();
    my_printf("%qu", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, qx_flag)
{
    long nb = 223372036854775807;
    char res[] = "31993af1d7bffff";

    cr_redirect_stdout();
    my_printf("%qx", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, qX_flag)
{
    long nb = 223372036854775807;
    char res[] = "31993AF1D7BFFFF";

    cr_redirect_stdout();
    my_printf("%qX", nb);
    cr_expect_stdout_eq_str(res);
}