/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr.c
*/

#include "gen.h"
#include "cstr.h"

void num_cstr(cstr_t *c_cstr, va_list list)
{
    char **array = NULL;
    char *str = NULL;

    if (enqual("%na", c_cstr->opt)) {
        array = va_arg(list, char **);
        for (int i = 0; array[i]; i++, c_cstr->c_n++);
    }
    if (enqual("%ns", c_cstr->opt)) {
        str = va_arg(list, char *);
        c_cstr->c_n += cstr_arglen(str, va_arg(list, int));
    }
    if (enqual("%nd", c_cstr->opt))
        c_cstr->c_n += int_size(va_arg(list, int));
}

void init_cstr(char *opt, va_list list, cstr_t *c_cstr)
{
    c_cstr->c_n = 0;
    c_cstr->c_str = NULL;
    c_cstr->c_array = NULL;
    if (enqual("%a", opt))
        c_cstr->type = ARRAY;
    else if (enqual("%s", opt))
        c_cstr->type = STR;
    if (enqual("%d", opt))
        c_cstr->type = INT;
    c_cstr->opt = my_strdup(opt);
}

void *cstr(char *opt, ...)
{
    va_list list;
    cstr_t *c_cstr = malloc(sizeof(cstr_t));

    va_start(list, opt);
    init_cstr(opt, list, c_cstr);
    for (; c_cstr->opt[0]; c_cstr->opt++) {
        num_cstr(c_cstr, list);
        cstr_parsing(c_cstr, list);
    }
    va_end(list);
    if (c_cstr->type == STR)
        return &c_cstr->c_str;
    if (c_cstr->type == ARRAY)
        return &c_cstr->c_array;
    return &c_cstr->c_n;
}
