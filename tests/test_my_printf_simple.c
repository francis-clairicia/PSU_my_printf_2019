/*
** EPITECH PROJECT, 2019
** Test my_printf()
** File description:
** Test a function
*/

#include <my_printf.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_printf, print_a_string)
{
    cr_redirect_stdout();
    my_printf("I am a test.");
    cr_expect_stdout_eq_str("I am a test.");
}

Test(my_printf, handle_d_flag)
{
    cr_redirect_stdout();
    my_printf("I am %d", 5);
    cr_expect_stdout_eq_str("I am 5");
}

Test(my_printf, handle_i_flag)
{
    cr_redirect_stdout();
    my_printf("You finished %ith", 12);
    cr_expect_stdout_eq_str("You finished 12th");
}

Test(my_printf, handle_c_flag)
{
    cr_redirect_stdout();
    my_printf("B%cSS", '0');
    cr_expect_stdout_eq_str("B0SS");
}

Test(my_printf, handle_s_flag)
{
    cr_redirect_stdout();
    my_printf("I %s complete", "will be");
    cr_expect_stdout_eq_str("I will be complete");
}

Test(my_printf, handle_percent_flag)
{
    cr_redirect_stdout();
    my_printf("%%");
    cr_expect_stdout_eq_str("%");
}

Test(my_printf, handle_multiple_flag_in_a_string)
{
    char fn[] = "Mickael";
    char ln[] = "Stanislas";
    int age = 32;
    char sis = '2';
    char expected[] = "I am Mickael Stanislas. I am 32 and I have 2 sisters.";

    cr_redirect_stdout();
    my_printf("I am %s %s. I am %d and I have %c sisters.", fn, ln, age, sis);
    cr_expect_stdout_eq_str(expected);
}
