/*
** EPITECH PROJECT, 2021
** bonus_42sh
** File description:
** get_altgr.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

bool get_altgr(var_t *var, float dc, bool *altgr)
{
    if (dc == 4294967296) {
        *altgr = true;
        return true;
    }
    return false;
}

char get_special_altgr(float d, char c, bool altgr)
{
    if (!altgr)
        return c;

    if (d == 56) {
        return '|';
    }
    return 0;
}
