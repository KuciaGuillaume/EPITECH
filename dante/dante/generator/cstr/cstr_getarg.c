/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_getarg.c
*/

#include "cstr.h"
#include "gen.h"

char *cstr_getarg(char *str, int n, char sep)
{
    char *copy = my_strdup(str);

    for (; n != 0; copy = move_to_next(copy, sep), n--);
    return cstr_grab(copy, sep);
}
