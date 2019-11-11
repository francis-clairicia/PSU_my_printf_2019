/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
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

static void get_infos(char type, char *modifiers, modifier_t *infos)
{
    int i = 0;

    infos->padding = my_getnbr(modifiers);
    while (modifiers[i] != '\0' && my_find_char("lhq", modifiers[i]) == -1) {
        if (modifiers[i] == '#' && my_find_char("oxX", type) >= 0)
            infos->sharp = 1;
        if (modifiers[i] == '0' && my_find_char(modifiers, '-') == -1) {
            infos->char_to_print = '0';
            infos->padding = my_getnbr(&modifiers[i + 1]);
        }
        if (modifiers[i] == '+' && my_find_char("di", type) >= 0)
            infos->print_sign = 1;
        if (modifiers[i] == '-') {
            infos->char_to_print = ' ';
            infos->padding = my_getnbr(&modifiers[i + 1]);
        }
        i += 1;
    }
    infos->lenght_modifier = &modifiers[i];
}

static int print_replacing_flag(char type, char *modifiers, va_list *args)
{
    int i = 0;
    modifier_t infos;

    get_infos(type, modifiers, &infos);
    while (flag_list[i].type != NULL) {
        if (my_find_char(flag_list[i].type, type) >= 0)
            return (flag_list[i].print(args, &infos));
        i += 1;
    }
    return (0);
}

static int get_modifiers(char **modifiers, char const *str)
{
    int i = 0;

    while (str[i] != '\0' && my_find_char("dibouxXcsSp", str[i]) == -1)
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
    if (format[*i] == '%'){
        my_putchar('%');
        return (1);
    }
    *i += get_modifiers(&modifiers, &format[*i]);
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
