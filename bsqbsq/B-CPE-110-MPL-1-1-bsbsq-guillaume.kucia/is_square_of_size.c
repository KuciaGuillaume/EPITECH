/*
** EPITECH PROJECT, 2021
** Work
** File description:
** is_square_of_size.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int i = 0;
    int e = 0;

    while (e != square_size) {
        while (map[row][i] != 'o') {
            if (map[row][col + i] == 'o')
                return 0;
            i += 1;
            e += 1;
        }
        i = 0;
        row += 1;
    }
    return 1;
}
