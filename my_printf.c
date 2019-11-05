/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

typedef struct flag_s
{
    char *type_list;
    void (*print)(va_list *);
} flag_t;

const flag_t flags[] = {
    {"di", &print_number},
    {"c", &print_char},
    {"s", &print_str},
    {"S", &print_str_non_printable},
    {NULL, NULL}
};

void print_replacing_flag(char type, va_list *args)
{
    int i = 0;

    if (my_find_char("bouxX", type) != -1) {
        print_number_base(args, type);
        return;
    }
    while (flags[i].type_list != NULL) {
        if (my_find_char(flags[i].type_list, type) != -1) {
            flags[i].print(args);
            return;
        }
        i += 1;
    }
}

int my_printf(char const *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] != '%') {
            my_putchar(format[i]);
        } else if (format[i + 1] == '%'){
            my_putchar('%');
        } else {
            print_replacing_flag(format[i + 1], &args);
            i += 1;
        }
        i += 1;
    }
    va_end(args);
    return (0);
}
