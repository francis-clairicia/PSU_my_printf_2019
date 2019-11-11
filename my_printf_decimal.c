
/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

static int print_short_short_u(unsigned char nb, modifier_t *infos)
{
    return (my_putnbr_base_u(nb, infos, "0123456789"));
}

static int print_short_u(unsigned short nb, modifier_t *infos)
{
    return (my_putnbr_base_u(nb, infos, "0123456789"));
}

static int print_int_u(unsigned int nb, modifier_t *infos)
{
    return (my_putnbr_base_u(nb, infos, "0123456789"));
}

static int print_long_u(unsigned long nb, modifier_t *infos)
{
    return (my_putnbr_base_u(nb, infos, "0123456789"));
}

int print_decimal(va_list *args, modifier_t *infos)
{
    unsigned long nb = va_arg(*args, unsigned long);
    char *l_mod = infos->lenght_modifier;

    if (my_strlen(l_mod) == 0)
        return (print_int_u(nb, infos));
    if (my_strcmp(l_mod, "ll") == 0 || my_strcmp(l_mod, "l") == 0
        || my_strcmp(l_mod, "q") == 0)
        return (print_long_u(nb, infos));
    if (my_strcmp(l_mod, "h") == 0)
        return (print_short_u(nb, infos));
    if (my_strcmp(l_mod, "hh") == 0)
        return (print_short_short_u(nb, infos));
    return (0);
}
