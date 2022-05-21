/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-guillaume.kucia
** File description:
** pastr.c
*/

#include <stdlib.h>
#include "my.h"
#include <stdarg.h>
#include <unistd.h>

void flags_3(char *arg, char **result, va_list list)
{
    int n = 0;
    char sep;

    if (nequal(arg, "%kip", 4)) {
        n = my_getnbr(arg + 4);
        sep = va_arg(list, int);
        n = new_arglen(*result, sep) - n;
        for (; new_arglen(*result, sep) > n; *result += 1);
    }
}

void flags_2(char *arg, char **result, va_list list)
{
    char rm = ' ';
    char *new = NULL;
    bool srm = false;

    flags_3(arg, result, list);
    if (nequal(arg, "%p", 2))
        put("%s\n", *result);
    if (nequal(arg, "%/", 2))
        *result = remove_backline(*result);
    if (nequal(arg, "%rm", 2)) {
        new = my_strdup("");
        rm = arg[3];
        srm = true;
    }
    for (int i = 0; srm && (*result)[i]; i++)
        if ((*result)[i] != rm)
            new = my_strcat_char(new, (*result)[i]);
    if (srm)
        *result = my_strdup(new);
}

void flags_1(char *arg, char **result, va_list list)
{
    char **tab = NULL;
    int n = 0;
    int beauty = 0;
    int g = 0;
    char sep;

    flags_2(arg, result, list);
    if (nequal(arg, "%n", 2) || nequal(arg, "%g", 2)) {
        sep = va_arg(list, int);
        n = my_getnbr(arg + 2);
        if (my_strlen(arg) > 2 + int_size(n) && arg[2 + int_size(n)] == 'b')
            beauty = 1;
        if (n > new_arglen(*result, sep))
            n = new_arglen(*result, sep);
        if (nequal(arg, "%g", 2))
            g = n;
        tab = mold_arg(*result, false, sep);
        *result = my_strdup("");
        for (int i = 0; i <= n - 1; i++)
            pastr_step(result, tab[i], sep, (int [3]){beauty, g - 1, i});
    }
}

void check_flag(char *arg, char **result, va_list list)
{
    if (nequal(arg, "%s", 2) && !nequal(arg, "%s/", 3))
        *result = rm_useless(*result, va_arg(list, int), true);
    if (nequal(arg, "%s/", 3))
        *result = rm_useless(*result, va_arg(list, int), false);
    flags_1(arg, result, list);
}

char *pastr(char *arg, ...)
{
    va_list list;
    va_start(list, arg);
    char *result = my_strdup(va_arg(list, char *));

    for (; arg[0]; arg++)
        check_flag(arg, &result, list);
    va_end(list);
    return result;
}
