/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** array_2d_how_many.c
*/

#include <stdlib.h>

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    int x = 0;
    int y = 0;
    int n = 0;

    while (y < nb_rows) {
        while (x < nb_cols) {
            if (arr[y][x] == number)
                n += 1;
            x += 1;
        }
        x = 0;
        y += 1;
    }
    return n;
}
