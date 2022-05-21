/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** input.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

char get_hard_input(var_t *var, char c, int d)
{
    if (d >= 75 && d <= 84)
        return d - 27;
    switch (d) {
        case -1: return ')';
        case 57: return ' ';
        case 56: return '-';
        case 67: return '+';
        case 68: return '-';
        case 69: return '*';
        case 70: return '/';
        case 27: return '&';
        case 51: return '\'';
        case 31: return '(';
        case 34: return '_';
        case 60: return '\t';
        case 48: return ';';
        case 29: return '"';
    }
    return c;
}

char get_special_input(int d, char c)
{
    switch (d) {
        case 52: return '/';
        case 48: return '.';
        case 51: return '4';
        case 56: return '6';
    }
    if (d >= 26 && d <= 35)
        return d + 22;
    if (d == 26)
        return '0';
    return c - 32;
}

void input(var_t *var, char **command)
{
    char c = 0;
    float d = engine.event.text.unicode;

    if (engine.event.type == sfEvtKeyPressed &&
    ((my_strlen((*command)) < 38) || (d == 59 && d != 38))) {
        if (d == 58)
            return;
        c = d + 97;
        if (key_press(sfKeyLShift))
            c = get_special_input(d, c);
        else if ((c < 65 || (c > 91 && c < 96) || c > 122) || d < 0)
            c = get_hard_input(var, c, d);
        if (d == 59 && d != 38)
            (*command)[my_strlen((*command)) - 1] = '\0';
        else if (d != 38)
            (*command) = my_strcat_char((*command), c);
    }
}
