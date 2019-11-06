/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

static const base_t base_nb[] = {
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
