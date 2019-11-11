/*
** EPITECH PROJECT, 2019
** my_nbr_len()
** File description:
** Lenght ofa number
*/

#include <my.h>

int my_nbr_len(long nb)
{
    int len = 1;

    if (nb < 0) {
        len = 2;
        nb = -nb;
    }
    while (nb > 9) {
        nb /= 10;
        len += 1;
    }
    return (len);
}
