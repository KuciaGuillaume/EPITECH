/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** falgs_X.c
*/

#include <stdlib.h>
#include "../include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void verif_flags_tags(int *i, char *my_str, struct printf *format)
{
    if (my_str[*i] == 'x') {
        if (format->tags == '#')
            my_putstr("0x");
        format->print_none = hexa_min(format->form, format->print_none, 0);
    } else {
        if (format->tags == '#')
            my_putstr("0X");
        format->print_none = hexa_maj(format->form, format->print_none, 0);
    }
}

long long int calc_strlen_int(long long int form)
{
    int i = 0;
    if (form > 0) {
        while (form > 0) {
            i += 1;
            form /= 10;
        }
    }
    if (form < 0) {
        while (form > 0) {
            i += 1;
            form *= 10;
        }
    }
    i -= 1;
    return i;
}

void verif_flags_x(int *i, char *my_str, va_list list, struct printf *format)
{
    format->form = 0;
    int size = 0;

    if (my_str[*i] == 'x' || my_str[*i] == 'X') {
        format->form = va_arg(list, int);
        size = calc_strlen_int(format->form);
        format->print_none = malloc(sizeof(char) * (size + 1));
        format->print_none[size] = '\0';
        verif_flags_tags(i, my_str, format);
        my_putstr(format->print_none);
    }
}