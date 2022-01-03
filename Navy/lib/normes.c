/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** normes
*/

#include "../include/my.h"

void respect_normes(int *i, char *my_str, va_list list)
{
    long long int form = 0;
    char *none;

    if (my_str[*i + 2] == 'x' || my_str[*i + 2] == 'X') {
        form = va_arg(list, long long int);
        none = malloc(sizeof(char) * (form + 3));
        none[form + 2] = '\0';
        if (my_str[*i + 2] == 'x')
            none = hexa_min(form, none, 0);
        else
            none = hexa_maj(form, none, 0);
        my_putstr(none);
        *i += 2;
    }
}

void respect_normes1(int *i, char *my_str, va_list list)
{
    long long int form = 0;
    char *none;

    if (my_str[*i + 1] == 'x' || my_str[*i + 1] == 'X') {
        form = va_arg(list, long int);
        none = malloc(sizeof(char) * (form + 3));
        none[form + 2] = '\0';
        if (my_str[*i + 1] == 'x')
            none = hexa_min(form, none, 0);
        else
            none = hexa_maj(form, none, 0);
        my_putstr(none);
        *i += 1;
        }
}
