/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <mylist.h>
#include <my_printf.h>

static const flag_t flag_list[] = {
    {"di", &print_number},
    {"c", &print_char},
    {"s", &print_str},
    {"S", &print_str_non_printable},
    {"p", &print_pointer},
    {NULL, NULL}
};

static int print_replacing_flag(linked_list_t *flags, va_list *args)
{
    int i = 0;
    int n = 0;

    if (my_find_char("bouxX", flags->character) != -1)
        return (print_number_base(args, flags->character));
    while (flag_list[i].type != NULL) {
        if (my_find_char(flag_list[i].type, flags->character) != -1)
            n = flag_list[i].print(args);
        i += 1;
    }
    return (n);
}

static int get_flags(linked_list_t **flags, char const *str)
{
    int i = 0;

    while (str[i] != '\0' && my_find_char("dibouxXcsSp", str[i]) == -1) {
        my_put_char_in_list(flags, str[i]);
        i += 1;
    }
    my_put_char_in_list(flags, str[i]);
    my_rev_list(flags);
    return (i);
}

static int my_printf_part2(char const *format, int *i, va_list *args)
{
    linked_list_t *flags = NULL;
    int n = 0;

    if (format[*i] != '%') {
        my_putchar(format[*i]);
        return (1);
    }
    *i += 1;
    if (format[*i] == '%'){
        my_putchar('%');
        return (1);
    }
    *i += get_flags(&flags, &format[*i]);
    n = print_replacing_flag(flags, args);
    my_free_list(&flags);
    return (n);
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
