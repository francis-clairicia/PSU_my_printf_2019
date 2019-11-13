/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

int print_binary(va_list *args, modifier_t *infos)
{
    unsigned long nb = va_arg(*args, unsigned long);
    char *l_mod = infos->lenght_modifier;
    char base[] = "01";

    if (my_strcmp(l_mod, "ll") == 0 || my_strcmp(l_mod, "l") == 0
        || my_strcmp(l_mod, "q") == 0)
        return (my_putnbr_base_u((unsigned long)nb, infos, base));
    if (my_strcmp(l_mod, "h") == 0)
        return (my_putnbr_base_u((unsigned short)nb, infos, base));
    if (my_strcmp(l_mod, "hh") == 0)
        return (my_putnbr_base_u((unsigned char)nb, infos, base));
    return (my_putnbr_base_u((unsigned int)nb, infos, base));
}
