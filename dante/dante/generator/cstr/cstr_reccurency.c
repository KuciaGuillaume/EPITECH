/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_reccurency.c
*/

#include "gen.h"
#include "cstr.h"

void cstr_recurrency(cstr_t *cstr, va_list list)
{
    int n = 0;
    char *copy;

    if (enqual("%r", cstr->opt)) {
        n = my_getnbr(cstr->opt);
        cstr->recurency = true;
        cstr->opt += 3;
        copy = my_strdup(cstr->opt);
        for (; n != 0; cstr->opt = my_strcat(cstr->opt, copy), n--);
    }
}
