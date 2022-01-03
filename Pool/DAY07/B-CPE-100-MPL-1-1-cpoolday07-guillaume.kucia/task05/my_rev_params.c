/*
** EPITECH PROJECT, 2021
** my_rev_params.c
** File description:
** Day07 task05
*/

#include <unistd.h>

#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return 0;
}

int my_rev_params(int argc, char *argv[])
{
    int i = argc;

    while (i != 0) {
        my_putstr(argv[i-1]);
        my_putchar('\n');
        i--;
    }
}
