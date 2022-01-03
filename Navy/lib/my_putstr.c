/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** Day04 task02
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}
