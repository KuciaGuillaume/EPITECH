/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_gx.c
*/

#include "gen.h"
#include "cstr.h"

bool cstr_gx(cstr_t *cstr, va_list list)
{
    char *str = NULL;
    char sep = 'c';

    if (enqual("%gx", cstr->opt)) {
        str = va_arg(list, char *);
        sep = va_arg(list, int);
        cstr->c_str = cstr_getarg(str, cstr_arglen(str, sep) - 1, sep);
        return true;
    } else if (enqual("|gx", cstr->opt)) {
        sep = va_arg(list, int);
        cstr->c_str = cstr_getarg(cstr->c_str, cstr_arglen(
            cstr->c_str, sep) - 1, sep);
        return true;
    }
    return false;
}
