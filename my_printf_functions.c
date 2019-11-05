/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

typedef struct base_s
{
    char type;
    char *char_list;
} base_t;

const base_t base_nb[] = {
    {'b', "01"},
    {'o', "01234567"},
    {'u', "0123456789"},
    {'x', "0123456789abcdef"},
    {'X', "0123456789ABCDEF"},
    {'\0', NULL}
};

void print_number(va_list *args)
{
    int nb = va_arg(*args, int);

    my_put_nbr(nb);
}

void print_number_base(va_list *args, char type)
{
    int nb = va_arg(*args, int);
    int i = 0;

    while (base_nb[i].type != '\0') {
        if (type == base_nb[i].type) {
            my_putnbr_base(nb, base_nb[i].char_list);
            return;
        }
        i += 1;
    }
}

void print_char(va_list *args)
{
    char c = va_arg(*args, int);

    my_putchar(c);
}

void print_str(va_list *args)
{
    char *str = va_arg(*args, char *);

    my_putstr(str);
}

void print_str_non_printable(va_list *args)
{
    char *str = va_arg(*args, char *);

    my_showstr(str);
}
