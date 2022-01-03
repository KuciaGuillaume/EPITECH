/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** verif_more_less
*/

#include <stdlib.h>
#include "../include/my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void more_counter(int e, char *my_str, struct printf *format, int *i)
{
    format->counter = 0;

    while (my_str[e] >= '0' && my_str[e] <= '9') {
        format->counter *= 10;
        format->counter += my_str[e] - 48;
        e += 1;
        *i += 1;
    }
    format->counter += 1;
    format->my_more_counter = 1;
}

void put_my_more(int e, char *my_str, struct printf *format, int *i)
{
    char a = my_str[e + 1];
    char b = my_str[e + 2];
    char c = my_str[e + 3];

    if (a == 'd' || a == 'i')
        my_putchar('+');
    if ((a == 'l' && b == 'd') || (a == 'l' && b == 'i'))
        my_putchar('+');
    if ((a == 'l' && b == 'l' && c == 'd') ||
        (a == 'l' && b == 'l' && c == 'i'))
        my_putchar('+');
    if (my_str[e + 1] >= '0' && my_str[e + 1] <= '9')
        more_counter(e, my_str, format, i);
}

char my_tags(char *my_str, int h)
{
    int o = 0;
    char tab_tags[15] = {'c', 'd', 's', 'S', 'u', '%', 'b', 'o', 'p', 'x',
    'X', 'l', 'h', '#', '9'};

    while (o != 13) {
        if (tab_tags[o] == my_str[h])
            return 1;
        o += 1;
    }
    return 0;
}

int add_more(char *my_str, int *i)
{
    while (my_tags(my_str, *i) != 1)
        *i += 1;
    return 32;
}

int verif_more_less(int *i, char *my_str, struct printf *format)
{
    int e = *i;
    while (my_str[e] != '\0') {
        if (my_str[e] == '+') {
            put_my_more(e, my_str, format, i);
            return add_more(my_str, i);
        }
        e += 1;
    }
    while (my_tags(my_str, *i) != 1) {
        *i += 1;
    }
    return 0;
}
