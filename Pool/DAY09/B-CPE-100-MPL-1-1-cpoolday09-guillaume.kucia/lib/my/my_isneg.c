/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** N si valeur negative P si positive
*/


#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
