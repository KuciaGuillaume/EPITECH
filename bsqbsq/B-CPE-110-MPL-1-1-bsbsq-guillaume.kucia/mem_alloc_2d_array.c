/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** mem_alloc_2d_array_.c
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **array = malloc(nb_rows * sizeof(char *));
    int i = 0;

    while (i < nb_rows) {
        array[i] = malloc(nb_cols * sizeof(char));
        i += 1;
    }
    return array;
}
