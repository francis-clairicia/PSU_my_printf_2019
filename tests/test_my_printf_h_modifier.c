/*
** EPITECH PROJECT, 2019
** Test my_printf
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, hd_flag)
{
    short nb = 32700;
    char res[] = "32700";

    cr_redirect_stdout();
    my_printf("%hd", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hi_flag)
{
    short nb = 32700;
    char res[] = "32700";

    cr_redirect_stdout();
    my_printf("%hi", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hb_flag)
{
    short nb = 32700;
    char res[] = "111111110111100";

    cr_redirect_stdout();
    my_printf("%hb", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, ho_flag)
{
    short nb = 32700;
    char res[] = "77674";

    cr_redirect_stdout();
    my_printf("%ho", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hu_flag)
{
    short nb = 32700;
    char res[] = "32700";

    cr_redirect_stdout();
    my_printf("%hu", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hx_flag)
{
    short nb = 32700;
    char res[] = "7fbc";

    cr_redirect_stdout();
    my_printf("%hx", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hX_flag)
{
    short nb = 32700;
    char res[] = "7FBC";

    cr_redirect_stdout();
    my_printf("%hX", nb);
    cr_expect_stdout_eq_str(res);
}