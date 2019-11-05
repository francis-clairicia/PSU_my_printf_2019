/*
** EPITECH PROJECT, 2019
** my_nbr_to_str()
** File description:
** Put a number into a string
*/

#include <my.h>

int my_nbr_len(int nb)
{
    int len = 1;
    int multiple_of_ten = 1;

    while (nb / multiple_of_ten > 9) {
        multiple_of_ten *= 10;
        len += 1;
    }
    return (len);
}

char *my_nbr_to_str(int nb)
{
    int len = my_nbr_len(nb);
    char *str = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (str == NULL)
        return (NULL);
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
    } else {
        while (nb != 0) {
            str[i] = (nb % 10) + 48;
            nb /= 10;
            i += 1;
        }
        str[i] = '\0';
        my_revstr(str);
    }
    return (str);
}
