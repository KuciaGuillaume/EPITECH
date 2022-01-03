/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** Day04 task02
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a = a + 1;
    }
    return 0;
}
