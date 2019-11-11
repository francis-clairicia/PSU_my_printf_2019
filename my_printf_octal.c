/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

static int print_short_short_o(unsigned char nb, modifier_t *infos)
{
    int sharp_printed = 0;

    if (infos->sharp == 1 && nb > 0) {
        my_putchar('0');
        sharp_printed = 1;
    }
    return (sharp_printed + my_putnbr_base_u(nb, infos, "01234567"));
}

static int print_short_o(unsigned short nb, modifier_t *infos)
{
    int sharp_printed = 0;

    if (infos->sharp == 1 && nb > 0) {
        my_putchar('0');
        sharp_printed = 1;
    }
    return (sharp_printed + my_putnbr_base_u(nb, infos, "01234567"));
}

static int print_int_o(unsigned int nb, modifier_t *infos)
{
    int sharp_printed = 0;

    if (infos->sharp == 1 && nb > 0) {
        my_putchar('0');
        sharp_printed = 1;
    }
    return (sharp_printed + my_putnbr_base_u(nb, infos, "01234567"));
}

static int print_long_o(unsigned long nb, modifier_t *infos)
{
    int sharp_printed = 0;

    if (infos->sharp == 1 && nb > 0) {
        my_putchar('0');
        sharp_printed = 1;
    }
    return (sharp_printed + my_putnbr_base_u(nb, infos, "01234567"));
}

int print_octal(va_list *args, modifier_t *infos)
{
    unsigned long nb = va_arg(*args, unsigned long);
    char *l_mod = infos->lenght_modifier;

    if (my_strlen(l_mod) == 0)
        return (print_int_o(nb, infos));
    if (my_strcmp(l_mod, "ll") == 0 || my_strcmp(l_mod, "l") == 0
        || my_strcmp(l_mod, "q") == 0)
        return (print_long_o(nb, infos));
    if (my_strcmp(l_mod, "h") == 0)
        return (print_short_o(nb, infos));
    if (my_strcmp(l_mod, "hh") == 0)
        return (print_short_short_o(nb, infos));
    return (0);
}
