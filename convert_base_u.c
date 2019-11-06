/*
** EPITECH PROJECT, 2019
** convert_base
** File description:
** Convert a number from a base into an another
*/

#include <my_printf.h>
#include <mylist.h>

char *convert_to_base_u(unsigned int nbr, char const *base)
{
    linked_list_t *result = NULL;
    char *str_result = NULL;
    int nb_base = my_strlen(base);

    while (nbr != 0 || result == NULL) {
        my_put_char_in_list(&result, base[nbr % nb_base]);
        nbr /= nb_base;
    }
    str_result = my_list_to_string(result);
    my_free_list(&result);
    return (str_result);
}
