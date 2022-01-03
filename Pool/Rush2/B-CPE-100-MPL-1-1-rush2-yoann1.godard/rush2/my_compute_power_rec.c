/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it.c
** File description:
** DAY05 task04
*/

#include <stdio.h>
#include <unistd.h>

int my_compute_power_rec(int nb, int p)
{
    if (nb <= 0) {
        return 0;
    }
    return p == 1 ? nb : nb * my_compute_power_rec( nb, p-1) ;
}
