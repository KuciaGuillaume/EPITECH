/*
** EPITECH PrOJECT, 2021
** eval_expr
** File description:
** eval_expr.c
*/

#include <stdbool.h>
#include <stdio.h>
#include "lib/my/my.h"
#include <stdlib.h>

int parse_digits(char **str);
int parse_exp(char **str);

int parse_ftc(char **str)
{
    int r = 0;

    if ((*str)[0] == '(') {
        *str += 1;
        r = parse_exp(str);
        *str += 1;
        return r;
    } else if ((*str)[0] == '-' && (*str)[1] == '(') {
        *str += 2;
        r -= parse_exp(str);
        *str += 1;
        return r;
    } else {
        return parse_digits(str);
    }
}

int parse_trm(char **str)
{
    int r = parse_ftc(str);
    int play = 1;

    while (play == 1) {
        if ((*str)[0] == '/') {
            *str += 1;
            r /= parse_ftc(str);
        } else if ((*str)[0] == '%') {
            *str += 1;
            r %= parse_ftc(str);
        } else if ((*str)[0] == '*') {
            *str += 1;
            r *= parse_ftc(str);
        } else {
            play = 0;
        }
    }
    return r;
}

int parse_exp(char **str)
{
    int r = parse_trm(str);
    int play = 1;

    while (play == 1) {
        if ((*str)[0] == '+') {
            *str += 1;
            r += parse_trm(str);
        } else if ((*str)[0] == '-') {
            *str += 1;
            r -= parse_trm(str);
        } else {
            play = 0;
        }
    }
    return r;
}

int eval_expr(char const *str)
{
    int r = parse_exp((char**)(&str));
    return r;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
