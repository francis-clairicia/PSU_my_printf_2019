/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Modifiers
*/

#include <my_printf.h>

const format_t sharp_format[] = {
    {'o', "0", 1},
    {'x', "0x", 2},
    {'X', "0X", 2}
};

static int print_sharp_format(char type)
{
    int i = 0;

    while (i < 3) {
        if (sharp_format[i].type == type) {
            my_putstr(sharp_format[i].format);
            return (sharp_format[i].len);
        }
        i += 1;
    }
    return (0);
}

int print_before(modifier_t *infos, int size_print)
{
    int i = 0;
    int len = 0;

    if (infos->sharp == 1)
        len += print_sharp_format(infos->type);
    if (infos->sign > 0 && infos->char_to_print == '0') {
        my_putchar(infos->sign);
        len += 1;
    }
    while (i + size_print < infos->padding) {
        my_putchar(infos->char_to_print);
        i += 1;
    }
    if (infos->sign > 0 && infos->char_to_print == ' ') {
        my_putchar(infos->sign);
        len += 1;
    }
    return (len + i);
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
