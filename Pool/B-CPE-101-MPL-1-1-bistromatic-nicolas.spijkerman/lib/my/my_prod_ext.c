/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_prod_ext.c
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void set_prod_zero(bistro *prod)
{
    int e = 0;

    while (e != prod->i) {
        prod->nb[e] = '0';
        prod->y += 1;
        e += 1;
    }
}

void prod_separate_calc(bistro *prod)
{
    if (prod->x2 == 0) {
        prod->nb[prod->y] = (prod->rtn % 10) + 48;
        prod->y += 1;
        prod->limit += 1;
        prod->nb[prod->y] = (prod->rtn / 10) + 48;
        prod->rtn = 0;
    } else {
        prod->nb[prod->y] = (prod->rtn % 10) + 48;
        prod->rtn = (prod->rtn / 10);
    }
}
