/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** unpritable.c
*/

#include <stdarg.h>
#include "../include/my.h"

void unpritable_char_e(char *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            nb = octal(str[i]);
            if (nb < 10) {
                my_putchar('0');
                my_putchar('0');
            }
            if (nb < 100 && nb > 10)
                my_putchar('0');
            my_put_nbr(nb);
        } else {
            my_putchar(str[i]);
        }
        i += 1;
    }
}