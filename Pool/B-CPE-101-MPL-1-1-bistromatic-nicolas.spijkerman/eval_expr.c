/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** eval_expr.c
*/

#include "include/my.h"

void malloc_this(char **result, char *str);

char *parse_this(char **str, char *syntax)
{
    char *result;

    if (('0' <= **str && **str <= '9') || **str == syntax[3]) {
        malloc_this(&result, number(str));
    }
    return result;
}

char *eval_calc(char **str, char *syntax);

char *parenth(char **str, char *syntax)
{
    char *result;

    if (**str == syntax[0]) {
        (*str)++;
        malloc_this(&result, eval_calc(str, syntax));
        (*str)++;
        return result;
    } else if (**str == syntax[3] && *(*str + 1) == syntax[1]) {
        *str += 2;
        malloc_this(&result, sub(result, eval_calc(str, syntax)));
        (*str)++;
        return result;
    } else {
        return parse_this(str, syntax);
    }
}

char *priority(char **str, char *syntax)
{
    char *result = parenth(str, syntax);
    int stop = 0;

    while (stop == 0) {
        if (**str == syntax[5]) {
            (*str)++;
            malloc_this(&result, divi(result, parenth(str, syntax)));
        } else if (**str == syntax[4]) {
            (*str)++;
            malloc_this(&result, prod(result, parenth(str, syntax)));
        } else if (**str == syntax[6]) {
            (*str)++;
            malloc_this(&result, mod(result, parenth(str, syntax)));
        } else {
            stop = 1;
        }
    }
    return result;
}

char *eval_calc(char **str, char *syntax)
{
    char *result = priority(str, syntax);
    int stop = 0;

    while (stop == 0) {
        if (**str == syntax[2]) {
            (*str)++;
            malloc_this(&result, infin_add(result, priority(str, syntax)));
        } else if (**str == syntax[3]) {
            (*str)++;
            malloc_this(&result, sub(result, priority(str, syntax)));
        } else {
            stop = 1;
        }
    }
    return result;
}

char *eval_expr(char *base, char *syntax, char *expr, unsigned int size)
{
    int calc = 0;

    if (my_strlen(base) > 2)
        calc++;
    if (size > 0)
        calc++;
    if (calc == 2) {
        return eval_calc(&expr, syntax);
    }
    return "null";
}
