/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf.c
*/

#include <stdlib.h>
#include "../include/my.h"
#include <stdarg.h>
#include <unistd.h>

void write_my_foramt_3(int *i, char *my_str, va_list list)
{
    int format = 0;
    char *none;

    if (my_str[*i] == 'x'|| my_str[*i] == 'X') {
        format = va_arg(list, int);
        none = malloc(sizeof(char) * (format + 3));
        none[format + 2] = '\0';
        if (my_str[*i] == 'x')
            none = hexa_min(format, none, 0);
        else
            none = hexa_maj(format, none, 0);
        my_putstr(none);
    } else if (my_str[*i] == 'p') {
        format = va_arg(list, int);
        none = malloc(sizeof(char) * (format + 3));
        none[format + 2] = '\0';
        my_putstr("0x");
        none = hexa_min(format, none, 0);
        my_putstr(none);
    }
}

void write_my_foramt_2(int *i, char *my_str, va_list list)
{
    if (my_str[*i] == 'o') {
        my_put_nbr(octal(va_arg(list, int)));
    }
    if (my_str[*i] == 'b') {
        my_put_nbr(binary(va_arg(list, int)));
    }
    if (my_str[*i] == '%') {
        my_putchar('%');
    }
    if (my_str[*i] == 'u') {
        my_put_nbr(va_arg(list, int));
    }
    write_my_foramt_3(i, my_str, list);
}

void write_my_format(int *i, char *my_str, va_list list)
{
    char *str;

    if (my_str[*i] == 'S') {
        str = (va_arg(list, char *));
        unpritable_char_e(str);
    }
    if (my_str[*i] == 's') {
        my_putstr(va_arg(list, char *));
    }
    if (my_str[*i] == 'd' || my_str[*i] == 'i')
        my_put_nbr(va_arg(list, int));
    if (my_str[*i] == 'c')
        my_putchar(va_arg(list, int));
    write_my_foramt_2(i, my_str, list);
}

void write_my_string(char const *string, va_list list)
{
    int i = 0;
    char *my_str = my_strdup(string);

    while (my_str[i] != '\0') {
        if (my_str[i] == '%') {
            i += 1;
            write_my_format(&i, my_str, list);
            i += 1;
        } else {
            my_putchar(my_str[i]);
            i += 1;
        }
    }
}

int my_printf(char const *string, ...)
{
    va_list list;
    va_start(list, string);
    int er = error(string);

    if (er == 84) {
        write(2, "error, flag not handled\n", 25);
        return 84;
    }
    write_my_string(string, list);
    va_end(list);
    return 0;
}
