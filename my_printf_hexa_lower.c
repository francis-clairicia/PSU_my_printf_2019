/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

static int print_short_short_x(unsigned char nb, modifier_t *infos)
{
    int sharp_printed = 0;

    if (infos->sharp == 1 && nb > 0) {
        my_putstr("0x");
        sharp_printed = 2;
    }
    return (sharp_printed + my_putnbr_base_u(nb, infos, "0123456789abcdef"));
}

static int print_short_x(unsigned short nb, modifier_t *infos)
{
    int sharp_printed = 0;

    if (infos->sharp == 1 && nb > 0) {
        my_putstr("0x");
        sharp_printed = 2;
    }
    return (sharp_printed + my_putnbr_base_u(nb, infos, "0123456789abcdef"));
}

static int print_int_x(unsigned int nb, modifier_t *infos)
{
    int sharp_printed = 0;

    if (infos->sharp == 1 && nb > 0) {
        my_putstr("0x");
        sharp_printed = 2;
    }
    return (sharp_printed + my_putnbr_base_u(nb, infos, "0123456789abcdef"));
}

static int print_long_x(unsigned long nb, modifier_t *infos)
{
    int sharp_printed = 0;

    if (infos->sharp == 1 && nb > 0) {
        my_putstr("0x");
        sharp_printed = 2;
    }
    return (sharp_printed + my_putnbr_base_u(nb, infos, "0123456789abcdef"));
}

int print_hexa_lower(va_list *args, modifier_t *infos)
{
    unsigned long nb = va_arg(*args, unsigned long);
    char *l_mod = infos->lenght_modifier;

    if (my_strlen(l_mod) == 0)
        return (print_int_x(nb, infos));
    if (my_strcmp(l_mod, "ll") == 0 || my_strcmp(l_mod, "l") == 0
        || my_strcmp(l_mod, "q") == 0)
        return (print_long_x(nb, infos));
    if (my_strcmp(l_mod, "h") == 0)
        return (print_short_x(nb, infos));
    if (my_strcmp(l_mod, "hh") == 0)
        return (print_short_short_x(nb, infos));
    return (0);
}
