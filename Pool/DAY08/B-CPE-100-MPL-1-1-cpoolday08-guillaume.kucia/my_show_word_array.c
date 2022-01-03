/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** Day08 task03
*/

#include <unistd.h>

#include <stdio.h>

void my_putchar2(char c)
{
    write(1, &c, 1);
}

int my_putstr3(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar2(str[a]);
        a++;
    }
    return (0);
}

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr3(tab[i]);
        my_putchar2('\n');
        i++;
    }
    return 0;
}
