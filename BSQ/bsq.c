/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-guillaume.kucia
** File description:
** main.c
*/

#include "include/my.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int are_we_in_the_square(BSQ *file, int x, int y)
{
    if ((x > file->biggest_x - file->biggest_size) &&
    (x <= file->biggest_x) && (y > file->biggest_y - file->biggest_size) &&
    (y <= file->biggest_y))
        return 1;
    return 0;
}

void display_my_square(BSQ *file, int *x, int y)
{
    if (are_we_in_the_square(file, *x, y) == 1) {
        my_putchar('x');
        *x += 1;
    } else {
        if (file->map_array[y][*x] == 0)
            my_putchar('o');
        else
            my_putchar('.');
        *x += 1;
    }

}

void display_my_map(BSQ *file)
{
    int y = 1;
    int x = 0;

    while (file->map_array[y] != NULL) {
        if (x != file->columns) {
            display_my_square(file, &x, y);
        } else {
            my_putchar('\n');
            y += 1;
            x = 0;
        }
    }

}

void find_my_line_square(BSQ *file)
{
    int i = 0;
    int e = 0;

    while (file->buffer[i] != '\n')
        i += 1;
    i += 1;
    while (file->buffer[i] != '\n') {
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

int main(int argc, char **argv)
{
    char const *filepath = argv[argc - 1];
    struct stat bf;
    struct BSQ file;

    stat(filepath, &bf);
    file.size = bf.st_size;
    file.buffer = malloc(sizeof(char) * (file.size + 1));
    file.fd = open(filepath, O_RDONLY);
    read(file.fd, file.buffer, file.size);
    file.columns = map_count_columns(&file);
    if (error_handling(&file) == 84)
        return 84;
    if (file.lines > 1 && file.columns > 1) {
        file.map_array = map_to_array_int(&file);
        find_my_square(&file);
        display_my_map(&file);
    } else if (file.lines == 1)
        find_my_line_square(&file);
    else if (file.columns == 1)
        find_my_columns_square(&file);
    return 0;
}