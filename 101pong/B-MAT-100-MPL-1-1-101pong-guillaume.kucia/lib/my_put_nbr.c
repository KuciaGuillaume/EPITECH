/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-evalexpr-alice.hamadi
** File description:
** my_put_nbr.c
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
    }
    return 0;
}
