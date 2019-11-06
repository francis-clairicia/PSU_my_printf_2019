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

int print_number(va_list *args)
{
    int nb = va_arg(*args, int);

    my_put_nbr(nb);
    return (my_nbr_len(nb));
}

int print_number_base(va_list *args, char type)
{
    unsigned int nb = va_arg(*args, unsigned int);
    int i = 0;
    int n = 0;

    while (base_nb[i].type != '\0') {
        if (type == base_nb[i].type)
            n = my_putnbr_base_u(nb, base_nb[i].char_list);
        i += 1;
    }
    return (n);
}

int print_char(va_list *args)
{
    unsigned char c = va_arg(*args, int);

    write(1, &c, 1);
    return (1);
}

int print_str(va_list *args)
{
    char *str = va_arg(*args, char *);

    my_putstr(str);
    return (my_strlen(str));
}

static void print_char_as_octal(char c)
{
    char *nb = convert_to_base(c, "01234567");
    int len = my_strlen(nb);

    my_putchar('\\');
    while (len < 3) {
        my_putchar('0');
        len += 1;
    }
    my_putstr(nb);
    free(nb);
}

int print_str_non_printable(va_list *args)
{
    char *str = va_arg(*args, char *);
    int len = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32) {
            print_char_as_octal(str[i]);
            len += 4;
        } else {
            my_putchar(str[i]);
            len += 1;
        }
        i += 1;
    }
    return (len);
}
