/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** add.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void set_less(char **val1, char **val2, bistro *add)
{
    add->less = 0;

    if (*val1[0] == '-' && *val2[0] == '-') {
        *val1 = suppr_char(*val1, '-');
        *val2 = suppr_char(*val2, '-');
        add->less = 3;
    } else {
        if (*val1[0] == '-') {
            *val1 = suppr_char(*val1, '-');
            add->less = 1;
        }
        if (*val2[0] == '-') {
            *val2 = suppr_char(*val2, '-');
            add->less = 2;
        }
    }
}

char *calc_less(char *val1, char *val2, bistro *add)
{
    if (add->less == 1) {
        if (my_strcmp(val1, val2) == 0)
            add->result = "0";
    }
    if (add->less == 2) {
        if (my_strcmp(val1, val2) == 0)
            add->result = "0";
    }
    if (add->less == 3) {
        add->result = my_strcat(add->result, '-');
    }
    return add->result;
}

void separate_calc(char *val1, char *val2, bistro *add)
{
    if (add->x1 <= (-1) && add->x2 <= (-1)) {
        add->rtn = add->rtn;
    } else if (add->x2 <= (-1)) {
            add->rtn = ((val1[add->x1] - 48) + (0) + add->rtn);
     } else {
            add->rtn = ((val1[add->x1] - 48) + (val2[add->x2] - 48) + add->rtn);
     }
}

char *add_calc(char *val1, char *val2, bistro *add)
{
    separate_calc(val1, val2, add);
    if (add->rtn >= 10) {
        add->result[add->y] = (add->rtn % 10) + 48;
        if (add->x1 == 0)
            add->limit += 1;
        add->rtn = 1;
    } else {
        add->result[add->y] = (add->rtn) + 48;
        add->rtn = 0;
    }
    add->x1 -= 1;
    add->x2 -= 1;
    add->y += 1;
    if (add->y != add->limit)
        add->result = add_calc(val1, val2, add);
    return add->result;
}

char *add(char *val1, char *val2)
{
    bistro add;
    add.rtn = 0;
    add.y = 0;
    set_less(&val1, &val2, &add);
    add.result = add_ext(val1, val2, &add);

    if (my_strcmp(val1, val2) != 1)
        my_swap(&val1, &val2);
    add.x1 = my_strlen(val1) - 1;
    add.x2 = my_strlen(val2) - 1;
    add.limit = add.x1 + 1;
    add.result = malloc(sizeof(char) * (my_strlen(val1) + 2));
    add.result[my_strlen(val1) + 2] = '\0';
    add.result = add_calc(val1, val2, &add);
    add.result = my_revstr(add.result);
    add.result = calc_less(val1, val2, &add);
    return add.result;
}
