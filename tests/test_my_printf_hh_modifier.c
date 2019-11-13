/*
** EPITECH PROJECT, 2019
** Test my_printf
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my_printf.h>

Test(my_printf, hhd_flag)
{
    char nb = 127;
    char res[] = "127";

    cr_redirect_stdout();
    my_printf("%hhd", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hhi_flag)
{
    char nb = 127;
    char res[] = "127";

    cr_redirect_stdout();
    my_printf("%hhi", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hhb_flag)
{
    char nb = 127;
    char res[] = "1111111";

    cr_redirect_stdout();
    my_printf("%hhb", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hho_flag)
{
    char nb = 127;
    char res[] = "177";

    cr_redirect_stdout();
    my_printf("%hho", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hhu_flag)
{
    char nb = 127;
    char res[] = "127";

    cr_redirect_stdout();
    my_printf("%hhu", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hhx_flag)
{
    char nb = 127;
    char res[] = "7f";

    cr_redirect_stdout();
    my_printf("%hhx", nb);
    cr_expect_stdout_eq_str(res);
}

Test(my_printf, hhX_flag)
{
    char nb = 127;
    char res[] = "7F";

    cr_redirect_stdout();
    my_printf("%hhX", nb);
    cr_expect_stdout_eq_str(res);
}