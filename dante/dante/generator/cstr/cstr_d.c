/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_d.c
*/

#include "gen.h"
#include "cstr.h"

char *cstr_delete_str(char *str, char sep, int n)
{
    char *index = my_strcat("%s%g", my_itoa(n, 0));
    char **get = cstr(index, str, sep);
    char *copy = my_strdup(str);
    char *previous = my_strdup("");

    for (; !enqual(*get, copy); copy++)
        previous = my_strcat_char(previous, copy[0]);
    for (; copy[0] && copy[0] != sep; copy++);
    return my_strcat(previous, copy);
}

bool cstr_dx(cstr_t *cstr, va_list list, int n)
{
    char *str = NULL;
    char sep = 'c';

    if (enqual("%dx", cstr->opt)) {
        str = va_arg(list, char *);
        sep = va_arg(list, int);
        cstr->c_str = cstr_delete_str(str, sep, cstr_arglen(str, sep) - 1);
        return true;
    } else if (enqual("|dx", cstr->opt)) {
        sep = va_arg(list, int);
        cstr->c_str = cstr_delete_str(cstr->c_str, sep,
        cstr_arglen(str, sep) - 1);
        return true;
    }
    return false;
}

char *delete_allchar(char *str, char del)
{
    char *new = my_strdup("");

    for (int i = 0; str[i]; i++)
        if (str[i] != del)
            new = my_strcat_char(new, str[i]);
    return new;
}

void cstr_d_char(cstr_t *cstr, va_list list, int n)
{
    char *str = NULL;
    char delete = 'c';

    if (enqual("%d", cstr->opt)) {
        str = va_arg(list, char *);
        cstr->c_str = delete_allchar(str, va_arg(list, int));
    } else if (enqual("|d", cstr->opt))
        cstr->c_str = delete_allchar(cstr->c_str, va_arg(list, int));
}

void cstr_delete(cstr_t *cstr, va_list list)
{
    char *str = NULL;
    char sep = 'c';
    int n = -1;

    if (!enqual("%d", cstr->opt) && !enqual("|d", cstr->opt))
        return;
    n = my_getnbr(cstr->opt);
    if (n < 0) {
        cstr_d_char(cstr, list, n);
        return;
    }
    if (cstr_dx(cstr, list, n))
        return;
    if (enqual("%d", cstr->opt)) {
        str = va_arg(list, char *);
        cstr->c_str = cstr_delete_str(str, va_arg(list, int), n);
    } else if ("|d", cstr->opt)
        cstr->c_str = cstr_delete_str(cstr->c_str, va_arg(list, int), n);
}
