/*
** EPITECH PROJECT, 2021
** Bootstrap
** File description:
** bootstrap.c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
            write(1, *str_ptr, strlen(*str_ptr));
            return result;
        }
    }
}

int main(void)
{
    char *str_ptr = "91+4888";
    return number(&str_ptr);
}