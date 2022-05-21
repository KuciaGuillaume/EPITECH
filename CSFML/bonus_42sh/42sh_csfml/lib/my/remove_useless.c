/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-guillaume.kucia
** File description:
** remove_useless.c
*/

#include "my.h"

bool surch(char *str, char end, char no_view)
{
    for (int i = 0; str[i] && str[i] != end; i++)
        if (str[i] != no_view)
            return false;
    return true;
}

char *rm_before(char *str, char remove)
{
    for (; str[0] == remove; str++);
    return str;
}

char *remove_after(char *str, char remove)
{
    int i = 0;
    for (; str[i] != '\0'; i++);

    i--;
    if (i < 0)
        return str;
    while (str[i] == remove) {
        str[i] = '\0';
        i--;
    }
    return str;
}

char *reload(char *str, char remove, int i, char *result)
{
    if (str[i] == remove && str[i + 1] != remove) {
        result = my_strcat_char(result, str[i]);
        return result;
    }
    if (str[i] != remove) {
        result = my_strcat_char(result, str[i]);
        return result;
    }
    return result;
}

char *rm_useless(char *str, char remove, bool backline)
{
    int i = 0;
    char *result = "";

    if (backline)
        str = remove_backline(str);
    str = rm_before(str, remove);
    str = remove_after(str, remove);
    for (; str[i]; i++)
        result = reload(str, remove, i, result);
    return result;
}
