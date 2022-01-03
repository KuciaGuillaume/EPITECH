/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** sub.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void set_less_sub(char **val1, char **val2, bistro *sub)
{
    if (*val1[0] == '-' && *val2[0] == '-') {
        *val1 = suppr_char(*val1, '-');
        *val2 = suppr_char(*val2, '-');
        sub->less = 3;
    } else {
        if (*val1[0] == '-') {
            *val1 = suppr_char(*val1, '-');
            sub->less = 1;
        }
        if (*val2[0] == '-') {
            *val2 = suppr_char(*val2, '-');
            sub->less = 2;
            if (my_strcmp(*val1, *val2) == 2)
                sub->i = 2;
        }
    }
}

char *sub_calc(char *val1, char *val2, bistro *sub)
{
    if (sub->x2 <= (-1)) {
        my_separate_sub(val1, sub);
    } else if ((val1[sub->x1] - 48) < ((val2[sub->x2] - 48) + sub->rtn)) {
        sub->rtn = ((val1[sub->x1] - 48) + 10) - ((val2[sub->x2] - 48) + sub->rtn);
        sub->result[sub->y] = (sub->rtn) + 48;
        sub->rtn = 1;
    } else {
        sub->rtn = (val1[sub->x1] - 48) - ((val2[sub->x2] - 48) + sub->rtn);
        sub->result[sub->y] = (sub->rtn) + 48;
        sub->rtn = 0;
    }
    sub->x1 -= 1;
    sub->x2 -= 1;
    sub->y += 1;

    if (sub->y != sub->limit)
        sub->result = sub_calc(val1, val2, sub);
    return sub->result;
}

char *add_less(bistro *sub)
{
    int i = 0;

    while (sub->result[i] >= '1' && sub->result[i] <= '9') {
        i += 1;
    }
    if (sub->less != 3)
        sub->result = my_strcat(sub->result, '-');
    return sub->result;
}

void sub_space_saving(char *val1, char *val2, bistro *sub)
{
    sub->rtn = 0;
    sub->y = 0;
    sub->x1 = my_strlen(val1) - 1;
    sub->x2 = my_strlen(val2) - 1;
    sub->limit = sub->x1 + 1;
    sub->result = malloc(sizeof(char) * my_strlen(val1) + 2);
    sub->result[my_strlen(val1)] = '\0';

}

char *sub(char *val1, char *val2)
{
    bistro sub;
    sub.e = 0;
    sub.i = 0;
    sub_space_saving(val1, val2, &sub);
    set_less_sub(&val1, &val2, &sub);

    if (my_strcmp(val1, val2) != 1) {
        if (my_strcmp(val1, val2) == 2)
            sub.e = 1;
        my_swap(&val1, &val2);
    }
    sub_space_saving(val1, val2, &sub);
    if (sub.less == 1 || sub.i == 2 || sub.less == 2) {
        sub.result = sub_calc_un(val1, val2, &sub);
        sub.result = sub_set_zero(sub.result);
    } else {
        sub.result = sub_calc_deux(val1, val2, &sub);
    }
    return sub.result;
}
