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
    char test[] = "I am a test.";
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("I am a test.");
    cr_expect_stdout_eq_str(test);
    cr_expect_eq(n, my_strlen(test));
}

Test(my_printf, handle_d_flag)
{
    char test[] = "I am 5 years old";
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("I am %d years old", 5);
    cr_expect_stdout_eq_str(test);
    cr_expect_eq(n, my_strlen(test));
}

Test(my_printf, handle_i_flag)
{
    char test[] = "You finished 12th";
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("You finished %ith", 12);
    cr_expect_stdout_eq_str(test);
    cr_expect_eq(n, my_strlen(test));
}

Test(my_printf, handle_c_flag)
{
    char test[] = "B0SS";
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("B%cSS", '0');
    cr_expect_stdout_eq_str(test);
    cr_expect_eq(n, my_strlen(test));
}

Test(my_printf, handle_s_flag)
{
    char test[] = "I will be complete";
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("I %s complete", "will be");
    cr_expect_stdout_eq_str(test);
    cr_expect_eq(n, my_strlen(test));
}

Test(my_printf, handle_p_flag)
{
    char *test = my_strdup("Test");
    char buffer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n = 0;

    cr_redirect_stdout();
    sprintf(buffer, "%p", test);
    n = my_printf("%p", test);
    cr_expect_stdout_eq_str(buffer);
    cr_expect_eq(n, my_strlen(buffer));
    free(test);
}

Test(my_printf, handle_percent_flag)
{
    int n = 0;

    cr_redirect_stdout();
    n = my_printf("%%");
    cr_expect_stdout_eq_str("%");
    cr_expect_eq(n, 1);
}

Test(my_printf, handle_multiple_flag_in_a_string)
{
    char test[] = "I am Mickael Stanislas. I am 32 and I have 2 sisters.";
    char str[] = "I am %s %s. I am %d and I have %c sisters.";
    char first_name[] = "Mickael";
    char last_name[] = "Stanislas";
    int age = 32;
    char sisters = '2';
    int n = 0;

    cr_redirect_stdout();
    n = my_printf(str, first_name, last_name, age, sisters);
    cr_expect_stdout_eq_str(test);
    cr_expect_eq(n, my_strlen(test));
}
