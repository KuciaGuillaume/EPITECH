/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_separate_sub.c
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_separate_sub(char *val1, bistro *sub)
{
    sub->rtn = (val1[sub->x1] - 48) - (sub->rtn);
    if (sub->rtn >= 1) {
        sub->result[sub->y] = (sub->rtn) + 48;
        sub->rtn = 0;
    } else if (sub->rtn <= (-1)) {
        sub->result[sub->y] = '9';
        sub->rtn = 1;
    }
}
