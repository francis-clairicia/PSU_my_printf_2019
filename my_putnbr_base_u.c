/*
** EPITECH PROJECT, 2019
** My put nbr base
** File description:
** Base
*/

#include <my_printf.h>
#include <mylist.h>

int my_putnbr_base_u(unsigned int nbr, char const *base)
{
    char *nbr_converted = convert_to_base_u(nbr, base);
    int len = my_strlen(nbr_converted);

    my_putstr(nbr_converted);
    free(nbr_converted);
    return (len);
}
