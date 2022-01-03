/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** add_calc.c
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *add_ext(char *val1, char *val2, bistro *add)
{
    if (add->less == 1 && my_strcmp(val1, val2) == 2) {
        return sub(val2, val1);
    } else if (my_strcmp(val1, val2) == 1 && add->less == 1) {
        add->result = sub(val1, val2);
        return my_strcat(add->result, '-');
    }
    if (add->less == 2 && my_strcmp(val1, val2) == 2) {
        return sub(val1, val2);
    } else if (my_strcmp(val1, val2) == 1 && add->less == 2) {
        return sub(val1, val2);
    }
    return add->result;
}