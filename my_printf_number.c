/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** Recode the printf function
*/

#include <my_printf.h>

static int print_short_short(char nb, int plus)
{
    int sign = 0;

    if (nb == -128) {
        my_putstr("-128");
        return (my_strlen("-128"));
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        sign = 1;
    } else if (plus == 1) {
        my_putchar('+');
        sign = 1;
    }
    if (nb < 10)
        my_putchar(nb + 48);
    else
        return (sign + print_short_short(nb / 10, 0)
            + print_short_short(nb % 10, 0));
    return (1);
}

static int print_short(short nb, int plus)
{
    int sign = 0;

    if (nb == -32768) {
        my_putstr("-32768");
        return (my_strlen("-32768"));
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        sign = 1;
    } else if (plus == 1) {
        my_putchar('+');
        sign = 1;
    }
    if (nb < 10)
        my_putchar(nb + 48);
    else
        return (sign + print_short(nb / 10, 0) + print_short(nb % 10, 0));
    return (1);
}

static int print_int(int nb, int plus)
{
    int sign = 0;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (my_strlen("-2147483648"));
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        sign = 1;
    } else if (plus == 1) {
        my_putchar('+');
        sign = 1;
    }
    if (nb < 10)
        my_putchar(nb + 48);
    else
        return (sign + print_int(nb / 10, 0) + print_int(nb % 10, 0));
    return (1);
}

static int print_long(long nb, int plus)
{
    int sign = 0;

    if (nb < -9223372036854775807) {
        my_putstr("-9223372036854775808");
        return (my_strlen("-9223372036854775808"));
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        sign = 1;
    } else if (plus == 1) {
        my_putchar('+');
        sign = 1;
    }
    if (nb < 10)
        my_putchar(nb + 48);
    else
        return (sign + print_long(nb / 10, 0) + print_long(nb % 10, 0));
    return (1);
}

int print_number(va_list *args, modifier_t *infos)
{
    long nb = va_arg(*args, long);
    char *l_mod = infos->lenght_modifier;
    int plus = ((infos->print_sign == 1 && nb >= 0));
    int len = 0;

    len += print_before(infos, my_nbr_len(nb));
    if (my_strlen(l_mod) == 0)
        len += print_int(nb, plus);
    if (my_strcmp(l_mod, "ll") == 0 || my_strcmp(l_mod, "l") == 0
        || my_strcmp(l_mod, "q") == 0)
        len += print_long(nb, plus);
    if (my_strcmp(l_mod, "h") == 0)
        len += print_short(nb, plus);
    if (my_strcmp(l_mod, "hh") == 0)
        len += print_short_short(nb, plus);
    len += print_after(infos, my_nbr_len(nb));
    return (len);
}
