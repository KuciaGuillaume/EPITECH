/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-rush2-yoann1.godard
** File description:
** my_modulo.c
*/

#include <unistd.h>

#include <stdio.h>

int my_compute_power_rec(int nb, int p);

void my_putchar( char c);

int my_modulo( float number, float l)
{
    if (number == l) {
        my_putchar('1');
        my_putchar('0');
        my_putchar('0');
        my_putchar('.');
        my_putchar('0');
        my_putchar('0');
        return 0;
    }
    float x = number * 10000;
    x = x / l;
    int e = (int) x;
    int y = my_compute_power_rec( 10, 3);
    y = e / y;

    my_putchar(y + '0');

    y = my_compute_power_rec( 10, 2);
    y = e / y;

    y = (y % 10);
    my_putchar(y + '0');
    my_putchar('.');

    y = e / 10;
    y = (y % 10);
    my_putchar(y + '0');

    y = (e % 100);
    y = (y % 10);
    my_putchar(y + '0');
    return 0;
}