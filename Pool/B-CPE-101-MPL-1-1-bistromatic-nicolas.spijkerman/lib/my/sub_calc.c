/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** sub_calc.c
*/


#include "../../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *sub_calc_un(char *val1, char *val2, bistro *sub)
{
    sub->result = add(val1, val2);
    if (sub->i != 2 && sub->less != 2)
        sub->result = my_strcat(sub->result, '-');
    return sub->result;

}

char *sub_calc_deux(char *val1, char *val2, bistro *sub)
{
    sub->result = sub_calc(val1, val2, sub);
    sub->result = my_revstr(sub->result);
    sub->result = sub_set_zero(sub->result);
        if (sub->e != 0)
            sub->result = add_less(sub);
    return sub->result;

}

int set_space(char *str, int e, int i)
{
    int y = 0;

    e = 0;
    while (str[i] != '\0') {
        if (str[i] >= '1' && str[i] <= '9') {
            y = 1;
        }
        if (str[i] == '0' && y != 1) {
            e += 1;
        }
        i += 1;
    }
    return e;
}

char *sub_set_zero(char *str)
{
    int h = 0;
    int i = 0;
    int e = 0;
    e = set_space(str, e, i);
    char *result = malloc(sizeof(char) * ((my_strlen(str) + 1) - e));

    result[(my_strlen(str) + 1) - e] = '\0';
    while (str[i] != '\0') {
        if (i < e) {
            i += 1;
        } else {
            result[h] = str[i];
            i += 1;
            h += 1;
        }
    }
    if (result[0] < '0' || result[0] > '9')
        result [0] = '0';
    return result;
}
