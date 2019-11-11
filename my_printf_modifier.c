/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

int print_before(modifier_t *infos, int size_print)
{
    int i = 0;

    while (i + size_print < infos->padding) {
        my_putchar(infos->char_to_print);
        i += 1;
    }
    return (i);
}

int print_after(modifier_t *infos, int size_print)
{
    int i = 0;

    while (i - size_print > infos->padding) {
        my_putchar(' ');
        i -= 1;
    }
    return (-i);
}
