/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

const flag_t flags[] = {
    {"di", &print_number},
    {"c", &print_char},
    {"s", &print_str},
    {"S", &print_str_non_printable},
    {NULL, NULL}
};

static int print_replacing_flag(char type, va_list *args)
{
    int i = 0;
    int n = 0;

    if (my_find_char("bouxX", type) != -1)
        return (print_number_base(args, type));
    while (flags[i].type_list != NULL) {
        if (my_find_char(flags[i].type_list, type) != -1)
            n = flags[i].print(args);
        i += 1;
    }
    return (n);
}

static int my_printf_part2(char const *format, int *i, va_list *args)
{
    if (format[*i] != '%') {
        my_putchar(format[*i]);
        return (1);
    }
    *i += 1;
    if (format[*i] == '%'){
        my_putchar('%');
        return (1);
    }
    return (print_replacing_flag(format[*i], args));
}

int my_printf(char const *format, ...)
{
    va_list args;
    int i = 0;
    int nb_print = 0;

    va_start(args, format);
    while (format[i] != '\0') {
        nb_print += my_printf_part2(format, &i, &args);
        i += 1;
    }
    va_end(args);
    return (nb_print);
}
