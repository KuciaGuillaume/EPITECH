/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_cs_cattab.c
*/

#include "cstr.h"
#include "gen.h"

void cs_cattab(cstr_t *cstr, va_list list)
{
    char *str1 = NULL;
    char **tab = NULL;

    if (enqual("%ca", cstr->opt)) {
        tab = va_arg(list, char **);
        cstr->c_array = cstr_cattab(tab, va_arg(list, char **));
    } else if (enqual("|ca", cstr->opt))
        cstr->c_array = cstr_cattab(cstr->c_array, va_arg(list, char **));
    if (enqual("%c&as", cstr->opt)) {
        tab = va_arg(list, char **);
        cstr->c_array = cstr_cattab_str(tab, va_arg(list, char *));
    } else if (enqual("|c&as", cstr->opt))
        cstr->c_array = cstr_cattab_str(cstr->c_array, va_arg(list, char *));
}
