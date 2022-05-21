/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-guillaume.kucia
** File description:
** pastr_step.c
*/

#include "gen.h"

char *beauty_flag(char *str, char sep, int beauty)
{
    if (beauty == 0)
        return str;
    str = my_strcat_char(str, sep);
    return str;
}

void pastr_step(char **result, char *tab, char sep, int *di)
{
    if (di[1] == di[2] || di[1] == 0) {
        *result = my_strcat(*result, tab);
        *result = beauty_flag(*result, sep, di[0]);
    }
}
