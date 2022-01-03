/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-guillaume.kucia
** File description:
** find_my_columns_square.c
*/

#include "include/my.h"

void find_my_columns_square(BSQ *file)
{
    int i = 0;
    int e = 0;
    int a = file->lines - 1;

    while (file->buffer[i] != '\n')
        i += 1;
    i += 1;
    while (a != 0) {
        if (file->buffer[i] == '\n')
            a -= 1;
        if (file->buffer[i] == '.' && e == 0) {
            my_putchar('x');
            e = 1;
            i += 1;
        } else {
            my_putchar(file->buffer[i]);
            i += 1;
        }
    }
    my_putchar('\n');
}
