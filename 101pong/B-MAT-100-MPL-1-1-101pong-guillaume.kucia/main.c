/*
** EPITECH PROJECT, 2021
** B-MAT-100-MPL-1-1-101pong-guillaume.kucia
** File description:
** main.c
*/

#include "include/my.h"
#include <unistd.h>
#include <stdio.h>

int test_my_argv(char **argv)
{
    int y = 1;
    int x = 0;

    while (argv[y] != NULL) {
        if (argv[y][x] != '\0') {
            if ((argv[y][x] < '0' || argv[y][x] > '9') && (argv[y][x] != '-' &&
             argv[y][x] != '.') &&
            (argv[y][x] != 'h')) {
                return 84;
            }
            x += 1;
        } else {
            x = 0;
            y += 1;
        }
    }
    return 0;
}

int find_my_error(int argc, char **argv)
{
    int i = 0;
    if (argc == 8) {
        if (argv[argc - 1][0] == '-')
            return 84;
        while (argv[argc - 1][i] != '\0') {
            if (argv[argc - 1][i] == '.')
                return 84;
            i += 1;
        }
    }
    if (test_my_argv(argv) == 84) {
        return 84;
    }
    if (argc != 8 && argc != 2) {
        return 84;
    } else if (argc == 2) {
         if ((my_strcmp(argv[1], "-h") != 0))
            return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int i = find_my_error(argc, argv);
    if (i != 84)
        pong_(argv);
    return i;
}
