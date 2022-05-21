/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_arglen.c
*/

#include "gen.h"
#include "cstr.h"

int cstr_arglen(char *str, char sep)
{
    int result = 0;
    char *copy = my_strdup(str);

    while (copy[0]) {
        if (copy[0] == sep)
            copy = move_to_next(copy, sep);
        else {
            result++;
            copy = move_to_next(copy, sep);
        }
    };
    return result;
}
