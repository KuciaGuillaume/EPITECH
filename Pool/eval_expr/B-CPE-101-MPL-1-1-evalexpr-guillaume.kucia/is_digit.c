/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** is_digit.c
*/

#include "lib/my/my.h"

int is_digit(char c)
{
    if (('0' <= c && c <= '9') || (c == '-')) {
        return 1;
    } else {
        return 0;
    }
}
