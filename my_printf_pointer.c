/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** printf command-like
*/

#include <my.h>
#include <my_printf.h>
#include <mylist.h>

int print_pointer(va_list *args, modifier_t *infos)
{
    unsigned long nb = va_arg(*args, unsigned long);
    int len = 0;

    len += print_before(infos, my_nbr_len_u(nb));
    len += my_printf("%#lx", nb);
    len += print_after(infos, my_nbr_len_u(nb));
    return (len);
}
