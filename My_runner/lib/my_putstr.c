/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd01-guillaume.kucia
** File description:
** show_string.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1)
        my_putchar(str[i]);
    return 0;
}
