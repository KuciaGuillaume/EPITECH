/*
** EPITECH PROJECT, 2021
** workshoplib
** File description:
** factors.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int number(char **str_ptr)
{
    int i = 0;
    int result = 0;

    while ((*str_ptr)[i] != '\0') {
        if ((*str_ptr)[i] >= '0' && (*str_ptr)[i] <= '9') {
            result = result * 10;
            result = result + (*str_ptr)[i] - 48;
            i += 1;
        } else {
            *str_ptr = (&(*str_ptr)[i]);
            return result;
        }
    }
    *str_ptr = (&(*str_ptr)[i]);
    return result;
}

int my_strtol(char *str, char **endptr)
{
    *endptr = str;
    return number(endptr);
}

int factors_2(char **str_ptr, int sign, int *result)
{
    if (sign == '*') {
        *str_ptr += 1;
        *result = *result * number(str_ptr);
    }
    if (sign == '/') {
        *str_ptr += 1;
        *result = *result / number(str_ptr);
    }
    if (sign == '%') {
        *str_ptr += 1;
        *result = *result % number(str_ptr);
    }
    if (sign != '*' && sign != '/' && sign != '%' &&
    sign != '+' && sign != '-') {
        *result += number(str_ptr);
    }
}

int factors(char **str_ptr)
{
    int i = 0;
    int result = 0;
    char sign;

    while ((*str_ptr)[0] != '\0') {
        sign = (*str_ptr)[0];
        if (sign == '+') {
            *str_ptr += 1;
            result = result + number(str_ptr);
        }
        if (sign == '-') {
            *str_ptr += 1;
            result = result - number(str_ptr);
        }
        factors_2(str_ptr, sign, &result);
    }
    return result;
}
