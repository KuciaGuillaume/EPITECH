/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.kucia
** File description:
** more_flags
*/

#include <stdlib.h>
#include "../include/my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void more_flags_five(int *i, char *my_str, va_list list, struct printf *format)
{
    if (my_str[*i] == 'h' && (my_str[*i + 1] == 'i' ||
    my_str[*i + 1] == 'd')) {
        my_put_nbr_long_long(va_arg(list, int));
        *i += 1;
    }
    if (my_str[*i] == 'h' && my_str[*i + 1] == 'u') {
        my_put_nbr_short_unsigned(va_arg(list, unsigned int));
        *i += 1;
    }
    if (my_str[*i] == ' ' && format->valide_sp == 0) {
        if ((format->unused = verif_more_less(i, my_str, format)) == 0) {
            format->add_sp = 1;
            format->more = 1;
            write_format(i, my_str, list, format);
        } else if (format->unused == 32) {
            format->more = 1;
            write_format(i, my_str, list, format);
        }
    } else
        format->add_sp = 0;
}

void more_flags_four(int *i, char *my_str, va_list list, struct printf *format)
{
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'o') {
        my_put_nbr_unsigned(octal(va_arg(list, unsigned long int)));
        *i += 1;
    }
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'l' && my_str[*i +2] == 'o') {
        my_put_nbr_unsigned(octal(va_arg(list, unsigned long long int)));
        *i += 2;
    }
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'u') {
        my_put_nbr_unsigned(va_arg(list, unsigned long int));
        *i += 1;
    }
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'l' && my_str[*i +2] == 'u') {
        my_put_nbr_unsigned(va_arg(list, unsigned long long int));
        *i += 2;
    }
    format->unused += 1;
    more_flags_five(i, my_str, list, format);
}

void more_flg_three(int *i, char *my_str, va_list list, struct printf *format)
{
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'l') {
        respect_normes(i, my_str, list);
    }
    format->unused += 1;
    more_flags_four(i, my_str, list, format);
}

void more_flags_two(int *i, char *my_str, va_list list, struct printf *format)
{
    if (my_str[*i] == 'l') {
        respect_normes1(i, my_str, list);
    }
    format->unused += 1;
    more_flg_three(i, my_str, list, format);
}

void more_flags(int *i, char *my_str, va_list list, struct printf *format)
{
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'i') {
        my_put_nbr_long_long(va_arg(list, long int));
        *i += 1;
    }
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'l' && my_str[*i +2] == 'i') {
        my_put_nbr_long_long(va_arg(list, long long int));
        *i += 2;
    }
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'd') {
        my_put_nbr_long_long(va_arg(list, long int));
        *i += 1;
    }
    if (my_str[*i] == 'l' && my_str[*i + 1] == 'l' && my_str[*i +2] == 'd') {
        my_put_nbr_long_long(va_arg(list, long long int));
        *i += 2;
    }
    format->unused += 1;
    more_flags_two(i, my_str, list, format);
}
