/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

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
    unsigned int nb = va_arg(*args, unsigned int);
    int i = 0;

    while (base_nb[i].type != '\0') {
        if (type == base_nb[i].type) {
            my_putnbr_base_u(nb, base_nb[i].char_list);
            return;
        }
        i += 1;
    }
}

void print_char(va_list *args)
{
    unsigned char c = va_arg(*args, int);

    write(1, &c, 1);
}

void print_str(va_list *args)
{
    char *str = va_arg(*args, char *);

    my_putstr(str);
}

void print_str_non_printable(va_list *args)
{
    char *str = va_arg(*args, char *);
    char *tmp = NULL;
    int len = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32) {
            my_putchar('\\');
            tmp = convert_to_base(str[i], "01234567");
            len = my_strlen(tmp);
            while (len < 3) {
                my_putchar('0');
                len += 1;
            }
            my_putstr(tmp);
            free(tmp);
        } else
            my_putchar(str[i]);
        i += 1;
    }
}
