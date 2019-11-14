/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Recode the print function
*/

#include <my.h>
#include <my_printf.h>

static const flag_t flag_list[] = {
    {"di", &print_number},
    {"b", &print_binary},
    {"o", &print_octal},
    {"u", &print_decimal},
    {"x", &print_hexa_lower},
    {"X", &print_hexa_upper},
    {"c", &print_char},
    {"s", &print_str},
    {"S", &print_str_non_printable},
    {"p", &print_pointer},
    {NULL, NULL}
};

static int print_replacing_flag(char type, char *modifiers, va_list *args)
{
    int i = 0;
    int len = 0;
    modifier_t infos = {type, my_getnbr(modifiers), ' ', 0, 0, 0, NULL};

    get_infos(modifiers, &infos);
    while (flag_list[i].type != NULL) {
        if (my_find_char(flag_list[i].type, type) >= 0)
            len = (flag_list[i].print(args, &infos));
        i += 1;
    }
    return (len);
}

static int get_modifiers(char **modifiers, char const *str)
{
    int i = 0;

    while (str[i] != '\0' && my_find_char("%dibouxXcsSp", str[i]) == -1)
        i += 1;
    *modifiers = malloc(sizeof(char) * (i + 1));
    my_strncpy(*modifiers, str, i);
    (*modifiers)[i] = 0;
    return (i);
}

static int my_printf_part2(char const *format, int *i, va_list *args)
{
    char *modifiers = NULL;
    int n = 0;

    if (format[*i] != '%') {
        my_putchar(format[*i]);
        return (1);
    }
    *i += 1;
    *i += get_modifiers(&modifiers, &format[*i]);
    if (format[*i] == '%'){
        my_putchar('%');
        n = 1;
    } else
        n = print_replacing_flag(format[*i], modifiers, args);
    free(modifiers);
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
