/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include <stdlib.h>
#include "../include/my.h"
#include <stdarg.h>
#include <unistd.h>

void write_format_3(int *i, char *my_str, va_list list, struct printf *format)
{
    int form = 0;
    char *none;

    verif_flags_x(i, my_str, list, format);
    if (my_str[*i] == 'p') {
        form = va_arg(list, int);
        none = malloc(sizeof(char) * (form + 3));
        none[form + 2] = '\0';
        my_putstr("0x");
        none = hexa_min(form, none, 0);
        my_putstr(none);
    }
    more_flags(i, my_str, list, format);
}

void write_format_2(int *i, char *my_str, va_list list, struct printf *format)
{
    if (my_str[*i] == 'o') {
        format->var = octal(va_arg(list, unsigned int));
        if (format->tags == '#' && format->var != 0)
            my_putchar('0');
        my_put_nbr_long_long(format->var);
    }
    if (my_str[*i] == 'b') {
        my_put_nbr_long_long(binary(va_arg(list, int)));
    }
    if (my_str[*i] == '%') {
        my_putchar('%');
    }
    if (my_str[*i] == 'u') {
        my_put_nbr_unsigned(va_arg(list, unsigned int));
    }
    write_format_3(i, my_str, list, format);
}

void write_format(int *i, char *my_str, va_list list, struct printf *format)
{
    char *str;
    if (format->add_sp == 1) {
        my_putchar(' ');
        format->valide_sp = 1;
    }
    if (format->more == 1)
        more_steps(i, my_str, format);
    if (my_str[*i] == 'S') {
        str = (va_arg(list, char *));
        unpritable_char_e(str);
    }
    if (my_str[*i] == 's') {
        my_putstr(va_arg(list, char *));
    }
    if (my_str[*i] == 'd' || my_str[*i] == 'i')
        my_put_nbr_long_long(va_arg(list, int));
    if (my_str[*i] == 'c')
        my_putchar(va_arg(list, int));
    write_format_2(i, my_str, list, format);
}

void write_my_string(char *my_str, va_list list, struct printf *format, int *i)
{
    while (my_str[*i] != '\0') {
        if (my_str[*i] == '%' || format->add_sp == 1) {
            verif_tags(my_str, i, format);
            write_format(i, my_str, list, format);
            *i += 1;
        } else {
            my_putchar(my_str[*i]);
            *i += 1;
        }
    }
}

int my_printf(char const *string, ...)
{
    int i = 0;
    va_list list;
    va_start(list, string);
    struct printf format;
    format.add_sp = 0;
    format.more = 0;
    format.tags = 'c';
    format.my_more_counter = 0;
    format.valide_sp = 0;
    char *my_str = my_strdup(string);

    write_my_string(my_str, list, &format, &i);
    va_end(list);
    return 0;
}
