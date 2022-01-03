/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** prod.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void set_prod_less(char **val1, char **val2, bistro *prod)
{
    if (*val1[0] == '-' && *val2[0] == '-') {
        *val1 = suppr_char(*val1, '-');
        *val2 = suppr_char(*val2, '-');
        prod->less = 3;
    } else {
        if (*val1[0] == '-') {
            *val1 = suppr_char(*val1, '-');
            prod->less = 1;
        }
        if (*val2[0] == '-') {
            *val2 = suppr_char(*val2, '-');
            prod->less = 2;
        }
    }
}

void prod_initialize(char *val1, char *val2, bistro *prod)
{
    prod->rtn = 0;
    prod->x1 = my_strlen(val2) - 1;
    prod->x2 = my_strlen(val1) - 1;
    prod->i = 0;
    prod->y = 0;
    prod->limit = my_strlen(val1);
    prod->result = malloc(sizeof(char) * ((my_strlen(val1) + my_strlen(val2)) * (prod->i + 1)));
    prod->result[((my_strlen(val1) + my_strlen(val2)) * (prod->i))] = '\0';
}

char *prod_recursivity(char *val1, char *val2, bistro *prod)
{
    if (prod->x1 > (-1)) {
        prod->rtn = (((val1[prod->x2] - 48) * (val2[prod->x1] - 48)) + prod->rtn);
    } else {
        prod->rtn = ((val1[prod->x2] - 480) * (0) + prod->rtn);
    }
    if (prod->rtn >= 10) {
        prod_separate_calc(prod);
    } else {
        prod->nb[prod->y] = (prod->rtn) + 48;
        prod->rtn = 0;
    }
    prod->x2 -= 1;
    prod->y += 1;
    if (prod->y < prod->limit)
        prod->nb = prod_recursivity(val1, val2, prod);
    return prod->nb;
}

char *prod_calc(char *val1, char *val2, bistro *prod)
{
    prod->nb = malloc(sizeof(char) * ((my_strlen(val1) + my_strlen(val2)) * (prod->i + 1)));
    prod->nb[((my_strlen(val1) + my_strlen(val2)) * (prod->i))] = '\0';
    set_prod_zero(prod);
    prod->nb = prod_recursivity(val1, val2, prod);
    prod->nb = my_revstr(prod->nb);
    prod->x1 -= 1;
    prod->x2 = my_strlen(val1) - 1;
    if (prod->i == 0) {
        prod->result = prod->nb;
    } else {
        prod->result = add(prod->result, prod->nb);
    }
    prod->i += 1;
    prod->y = 0;
    if (prod->x1 != (-1))
        prod->result = prod_calc(val1, val2, prod);
    return prod->result;
}

char *prod(char *val1, char *val2)
{
    bistro prod;
    prod_initialize(val1, val2, &prod);
    set_prod_less(&val1, &val2, &prod);

    if (my_strcmp(val1, val2) != 1) {
        my_swap(&val1, &val2);
    }
    prod_initialize(val1, val2, &prod);
    prod.result = prod_calc(val1, val2, &prod);
    if (prod.less == 1 || prod.less == 2) {
        prod.result = my_strcat(prod.result, '-');
    }
    return prod.result;
}
