/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

static int print_short_short_b(unsigned char nb, modifier_t *infos)
{
    return (my_putnbr_base_u(nb, infos, "01"));
}

static int print_short_b(unsigned short nb, modifier_t *infos)
{
    return (my_putnbr_base_u(nb, infos, "01"));
}

static int print_int_b(unsigned int nb, modifier_t *infos)
{
    return (my_putnbr_base_u(nb, infos,  "01"));
}

static int print_long_b(unsigned long nb, modifier_t *infos)
{
    return (my_putnbr_base_u(nb, infos,  "01"));
}

int print_binary(va_list *args, modifier_t *infos)
{
    unsigned long nb = va_arg(*args, unsigned long);
    char *l_mod = infos->lenght_modifier;

    if (my_strlen(l_mod) == 0)
        return (print_int_b(nb, infos));
    if (my_strcmp(l_mod, "ll") == 0 || my_strcmp(l_mod, "l") == 0
        || my_strcmp(l_mod, "q") == 0)
        return (print_long_b(nb, infos));
    if (my_strcmp(l_mod, "h") == 0)
        return (print_short_b(nb, infos));
    if (my_strcmp(l_mod, "hh") == 0)
        return (print_short_short_b(nb, infos));
    return (0);
}
