/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-evalexpr-alice.hamadi
** File description:
** my_putstr.c
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
