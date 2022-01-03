/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_find_prime_sup.c
*/

#include <stdio.h>

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = (nb - 1);

    while (my_is_prime(i) == 0) {
        i += 1;
    }
    return i;
}
