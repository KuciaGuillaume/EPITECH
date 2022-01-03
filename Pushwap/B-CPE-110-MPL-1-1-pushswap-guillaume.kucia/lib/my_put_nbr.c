/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-evalexpr-alice.hamadi
** File description:
** my_put_nbr.c
*/

#include "../include/my.h"

long long int my_put_nbr_long_long(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr_long_long(nb * -1);
    }
    if (nb > 9) {
        my_put_nbr_long_long(nb / 10);
        my_put_nbr_long_long(nb % 10);
    }
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
    }
    return 0;
}

unsigned long long int my_put_nbr_unsigned(unsigned long long int nb)
{
    if (nb > 9) {
        my_put_nbr_unsigned(nb / 10);
        my_put_nbr_unsigned(nb % 10);
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    return 0;
}

short int my_put_nbr_short(short int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr_short(nb * -1);
    }
    if (nb > 9) {
        my_put_nbr_short(nb / 10);
        my_put_nbr_short(nb % 10);
    }
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
    }
    return 0;
}

unsigned short int my_put_nbr_short_unsigned(unsigned short int nb)
{
    if (nb > 9) {
        my_put_nbr_short_unsigned(nb / 10);
        my_put_nbr_short_unsigned(nb % 10);
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    return 0;
}
