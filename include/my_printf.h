/*
** EPITECH PROJECT, 2019
** my_printf Header
** File description:
** Header for my_printf()
*/

#include <my.h>
#include <stdarg.h>

#ifndef HEADER_MY_PRINTF
#define HEADER_MY_PRINTF

typedef struct flag_s
{
    char *type_list;
    int (*print)(va_list *);
} flag_t;

typedef struct base_s
{
    char type;
    char *char_list;
} base_t;

int my_printf(char const *format, ...);
int print_number(va_list *args);
int print_number_base(va_list *args, char type);
int print_char(va_list *args);
int print_str(va_list *args);
int print_str_non_printable(va_list *args);

char *convert_to_base_u(unsigned int nb, char const *base);
int my_putnbr_base_u(unsigned int nb, char const *base);

#endif
