/*
** EPITECH PROJECT, 2021
** dante
** File description:
** cvt_to_hard.c
*/

#include "my.h"

int cvt_to_hard(int x, int y, opt_t *opt)
{
    return (((y) * (opt->ln)) + x);
}
