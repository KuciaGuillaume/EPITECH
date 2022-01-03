/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-guillaume.kucia
** File description:
** allocate_my_2d_array.c
*/

#include "include/my.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void map_count_loop(int *a, int *i, int *e)
{
    if (*a >= *e)
        *e = *a;
    *i += 1;
    *a = 0;
}

int map_count_columns(struct BSQ *file)
{
    int i = 0;
    int e = 0;
    int a = 0;

    while (file->buffer[i] != '\n')
        i += 1;
    i += 1;
    while (i != file->size - 1) {
        if (file->buffer[i] == '\n') {
            map_count_loop(&a, &i, &e);
        } else {
            a += 1;
            i += 1;
        }
    }
    return e;
}

int *my_calloc(int *str, struct BSQ *file)
{
    int i = 0;

    while (i != file->columns) {
        str[i] = 0;
        i += 1;
    }
    str[i] = '\0';
    return str;
}

int **allocate_my_2d_array(struct BSQ *file)
{
    int i = 0;
    file->map_array = malloc((file->lines + 2) * sizeof(int *));
    file->map_array[file->lines + 1] = NULL;

    while (i <= file->lines) {
        file->map_array[i] = malloc((file->columns * sizeof(int)) + 1);
        file->map_array[i] = my_calloc(file->map_array[i], file);
        i += 1;
    }
    return file->map_array;
}

int **map_to_array_int(struct BSQ *file)
{
    int y = 0;
    int x = 0;
    int i = 0;

    file->map_array = allocate_my_2d_array(file);
    while (y != file->lines + 1) {
        if (file->buffer[i] != '\n') {
            replace_my_map(file, x, y, i);
            x += 1;
            i += 1;
        } else {
            i += 1;
            x = 0;
            y += 1;
        }
    }
    return file->map_array;
}