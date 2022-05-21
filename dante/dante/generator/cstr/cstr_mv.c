/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_mv.c
*/

#include "gen.h"
#include "cstr.h"

char *cstr_mvs(char *str, char sep, int n)
{
    for (; n != 0; str = move_to_next(str, sep), n--);
    return str;
}

void cstr_mv(cstr_t *cstr, va_list list)
{
    int n = 0;
    char *str = NULL;

    if (!enqual("%mv", cstr->opt) && !enqual("|mv", cstr->opt))
        return;
    n = my_getnbr(cstr->opt);
    if (enqual("%mv", cstr->opt)) {
        str = va_arg(list, char *);
        cstr->c_str = cstr_mvs(str, va_arg(list, int), n);
    } else if (enqual("|mv", cstr->opt))
        cstr->c_str = cstr_mvs(cstr->c_str, va_arg(list, int), n);
}
