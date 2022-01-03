/*
** EPITECH PROJECT, 2021
** my_print_params.c
** File description:
** Day07 task04
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

int my_print_params(int argc, char *argv[])
{
    int m = 0;

    while (m < argc) {
        my_putstr(argv[m]);
        m++;
        my_putchar('\n');
    }
    return (0);
}
