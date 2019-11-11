/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Base conversion
*/

#include <my_printf.h>

int my_putnbr_base_u(unsigned long nb, modifier_t *infos, char const *base)
{
    char *nb_converted = convert_to_base_u(nb, base);
    int size = my_strlen(nb_converted);
    int len = size;

    len += print_before(infos, size);
    my_putstr(nb_converted);
    len += print_after(infos, size);
    return (len);
}
