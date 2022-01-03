/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** put_nbr.c
*/

#include <unistd.h>

int my_putstr(char const *str);

void my_putchar(char c)
{
    write(1, &c, 1);
}

int positive(int nb, int digits)
{
    if (nb > 9) {
        digits = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(digits + 48);
    } else {
        my_putchar(nb % 10 + 48);
    }
}

int my_put_nbr(int nb)
{
    int digits;
    if (nb == -2147483648) {
        my_putstr(digits);
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        if (nb >= 0) {
            positive(nb, digits);
        }
    }
    return 0;
}
