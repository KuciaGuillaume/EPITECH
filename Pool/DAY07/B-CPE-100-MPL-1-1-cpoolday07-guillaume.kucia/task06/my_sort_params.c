/*
** EPITECH PROJECT, 2021
** my_sort_params.c
** File description:
** Day07 task06
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

int my_strcmp(char const *s1, char const *s2)
{
    while ((*s1 == *s2) && (*s1 != '\0')) {
        s1 = s1 + 1;
        s2 = s2 + 1;
    }
    return (*s1 - *s2);
}

int my_sort_params(int argc, char *argv[])
{
    int i = 0;
    int l = 0;
    char *mot;

    while (i != argc - 1) {
        if (my_strcmp(argv[i], argv[i + 1]) > 0) {
            mot = argv[i + 1];
            argv[i + 1] = argv[i];
            argv[i] = mot;
            i = 0;
        } else {
            i++;
        }
    }

    while (l != argc) {
        my_putstr(argv[l]);
        my_putchar('\n');
        l++;
    }
}
