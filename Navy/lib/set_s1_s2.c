/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** set_s1&s2.c
*/

#include "../include/my.h"

void set_s1_and_s2(signals_t *signals, int *s1, int *s2)
{
    if (signals->player == 1) {
        *s1 = 12;
        *s2 = 10;
    } else if (signals->player == 2) {
        *s1 = 10;
        *s2 = 12;
    }
}
