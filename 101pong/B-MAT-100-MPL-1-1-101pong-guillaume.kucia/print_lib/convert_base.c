/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** convert_base.c
*/


#include <stdarg.h>
#include "../include/my.h"
#include <stdio.h>

int octal(int nb)
{
    int i = 1;
    int oct = 0;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    while (nb != 0) {
        oct = oct + ((nb % 8) * i);
        i *= 10;
        nb /= 8;
    }
    return oct;
}

int binary(int str)
{
    int result = 0;

    if (str < 0)
        my_putchar('-');
    while (str != 0) {
        if (str % 2 == 1) {
            if (result == 0)
                result = 1;
            else
                result = (result*10) + 1;
        } else
            result *= 10;
        str /= 2;
    }
    return result;
}

char *hexa_min(int nb, char *str, int i)
{
    str[i] = (nb % 16) + '0';
    if (str[i] == 58)
        str[i] = 'a';
    if (str[i] == 59)
        str[i] = 'b';
    if (str[i] == 60)
        str[i] = 'c';
    if (str[i] == 61)
        str[i] = 'd';
    if (str[i] == 62)
        str[i] = 'e';
    if (str[i] == 63)
        str[i] = 'f';
    nb /= 16;
    i += 1;
    if (nb != 0)
        str = hexa_min(nb, str, i);
    str = my_revstr(str);
    return str;
}

char *hexa_maj(int nb, char *str, int i)
{
    str[i] = (nb % 16) + '0';
    if (str[i] == 58)
        str[i] = 'A';
    if (str[i] == 59)
        str[i] = 'B';
    if (str[i] == 60)
        str[i] = 'C';
    if (str[i] == 61)
        str[i] = 'D';
    if (str[i] == 62)
        str[i] = 'E';
    if (str[i] == 63)
        str[i] = 'F';
    nb /= 16;
    i += 1;
    if (nb != 0)
        str = hexa_maj(nb, str, i);
    str = my_revstr(str);
    return str;
}
