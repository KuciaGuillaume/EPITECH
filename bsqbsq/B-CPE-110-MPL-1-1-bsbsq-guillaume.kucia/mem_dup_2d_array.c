/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** mem_dup_2d_array.c
*/

#include <stdlib.h>

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **array = malloc(nb_rows * sizeof(char *));
    int i = 0;
    int x = 0;

    while (i < nb_rows) {
        array[i] = malloc(nb_cols * sizeof(char));
        i += 1;
    }
    i = 0;
    while (i < nb_rows) {
        if (x < nb_cols) {
            array[i][x] = arr[i][x];
            x += 1;
        } else {
            i += 1;
            x = 0;
        }
    }
    return array;
}
