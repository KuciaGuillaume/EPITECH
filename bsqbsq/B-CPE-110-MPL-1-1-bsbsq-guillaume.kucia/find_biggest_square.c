/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** find_biggest_square.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int find_biggest_square(char **map, int nb_rows, int nb_cols, int row, int col)
{
    int i = 0;
    int size_x = 0;
    int size_y = 1;
    int size_square = 0;


    while (map[row][col] != 'o') {

        while (map[row][col + i] == '.') {
            i += 1;
        }
        if (size_y == i)
            size_square = size_y + i;
        size_y += 1;
        i = 0;
        row += 1;
    }
    return size_square;
}
