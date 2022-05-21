/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_parsing.c
*/

#include "gen.h"
#include "cstr.h"

void cs(cstr_t *cstr, va_list list)
{
    char *str1 = NULL;
    char **tab = NULL;

    if (enqual("%cs", cstr->opt)) {
        str1 = va_arg(list, char *);
        cstr->c_str = my_strcat(str1, va_arg(list, char *));
    } else if (enqual("|cs", cstr->opt))
        cstr->c_str = my_strcat(cstr->c_str, va_arg(list, char *));
    if (enqual("%cd", cstr->opt)) {
        str1 = va_arg(list, char *);
        cstr->c_str = my_strcat_char(str1, va_arg(list, int));
    } else if (enqual("|cd", cstr->opt))
        cstr->c_str = my_strcat_char(cstr->c_str, va_arg(list, int));
    cs_cattab(cstr, list);
}

void bs(cstr_t *cstr, va_list list)
{
    char *str = NULL;

    if (enqual("%bs", cstr->opt)) {
        str = va_arg(list, char *);
        cstr->c_str = cstr_useless(str, va_arg(list, int));
    }
    if (enqual("|bs", cstr->opt))
        cstr->c_str = cstr_useless(cstr->c_str, va_arg(list, int));

}

bool cstr_gl(cstr_t *cstr, va_list list)
{
    char *str = NULL;
    int n = 0;

    if (enqual("%gl", cstr->opt)) {
        str = va_arg(list, char *);
        n = va_arg(list, int);
        for (; my_strlen(str) != n; str++);
        cstr->c_str = str;
        return true;
    } else if (enqual("|gl", cstr->opt)) {
        n = va_arg(list, int);
        for (; my_strlen(cstr->c_str) != n; cstr->c_str++);
        return true;
    }
    return false;
}

void get(cstr_t *cstr, va_list list)
{
    char *str = NULL;
    char sep = 'c';
    int n = 0;

    if (!enqual("%g", cstr->opt) && !enqual("|g", cstr->opt))
        return;
    n = my_getnbr(cstr->opt);
    if (cstr->opt[2] == '0')
        n = 0;
    if (cstr_gl(cstr, list))
        return;
    if (cstr_gx(cstr, list))
        return;
    if (enqual("%g", cstr->opt)) {
        str = va_arg(list, char *);
        cstr->c_str = cstr_getarg(str, n, va_arg(list, int));
    } else if ("|g", cstr->opt)
        cstr->c_str = cstr_getarg(cstr->c_str, n, va_arg(list, int));
}

void cstr_parsing(cstr_t *cstr, va_list list)
{
    cs(cstr, list);
    bs(cstr, list);
    get(cstr, list);
    cstr_mv(cstr, list);
    cstr_delete(cstr, list);
    cstr_recurrency(cstr, list);
}
