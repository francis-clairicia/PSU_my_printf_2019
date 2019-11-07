/*
** EPITECH PROJECT, 2019
** my_printf()
** File description:
** printf command-like
*/

#include <my.h>
#include <my_printf.h>
#include <mylist.h>

static char *get_pointer(unsigned long ptr_value)
{
    char base[] = "0123456789abcdef";
    linked_list_t *list = NULL;
    char *ptr = NULL;

    while (ptr_value > 0) {
        my_put_char_in_list(&list, base[ptr_value % 16]);
        ptr_value /= 16;
    }
    my_put_char_in_list(&list, 'x');
    my_put_char_in_list(&list, '0');
    ptr = my_list_to_string(list);
    my_free_list(&list);
    return (ptr);
}

int print_pointer(va_list *args)
{
    unsigned long ptr_value = va_arg(*args, unsigned long);
    char *ptr = get_pointer(ptr_value);
    int len = my_strlen(ptr);

    my_putstr(ptr);
    free(ptr);
    return (len);
}
