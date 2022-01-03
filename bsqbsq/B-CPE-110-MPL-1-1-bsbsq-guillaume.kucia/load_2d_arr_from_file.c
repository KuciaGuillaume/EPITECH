/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** load.2d.arr.from.file.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char **array_allocate(int nb_rows, int nb_cols)
{
    char **array = malloc(nb_rows * sizeof(char *));
    int i = 0;

    while (i < nb_rows) {
        array[i] = malloc(nb_cols * sizeof(char));
        i += 1;
    }
    return array;
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    struct stat buf;
    stat(filepath, &buf);
    char **array = array_allocate(nb_rows, nb_cols);
    char *buffer = malloc(sizeof(char) * (buf.st_size));
    int y = 0;
    int x = 0;
    int e = 0;
    int fd = open(filepath, O_RDONLY);
    int i = read(fd, buffer, buf.st_size);

    while (y < nb_rows) {
        if (x < nb_cols) {
            array[y][x] = buffer[e];
            x += 1;
            e += 1;
        } else {
            x = 0;
            y += 1;
        }
    }
    return array;
}
