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

int my_printf(char const *format, ...);
void print_number(va_list *args);
void print_number_base(va_list *args, char type);
void print_char(va_list *args);
void print_str(va_list *args);
void print_str_non_printable(va_list *args);

#endif
