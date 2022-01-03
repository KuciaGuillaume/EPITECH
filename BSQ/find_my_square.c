/*
** EPITECH PROJECT, 2021
** Nouvelles_algo
** File description:
** find_my_square.c
*/

#include "include/my.h"

int find_smaller_number(int d, int s, int w)
{
    if (w <= s && w <= d)
        return w;
    if (s <= d && s <= w)
        return s;
    if (d <= s && d <= w)
        return d;
    return 0;
}

void execute_square_calc(BSQ *file)
{
    int d = file->map_array[file->y - 1][file->x];
    int s = file->map_array[file->y - 1][file->x - 1];
    int w = file->map_array[file->y][file->x - 1];

    file->smaller = find_smaller_number(d, s, w);
    file->case_r = 0;
    if (file->map_array[file->y][file->x] != 0) {
        file->case_r = file->smaller + 1;
        file->map_array[file->y][file->x] = (file->case_r);
    }
    if (file->case_r > file->biggest_size) {
        file->biggest_size = file->case_r;
        file->biggest_x = file->x;
        file->biggest_y = file->y;
    }
}

void execute_square_loop(BSQ *file)
{
    while (file->y != file->lines + 1) {
        if (file->x != file->columns) {
            execute_square_calc(file);
            file->x += 1;
        } else {
            file->x = 1;
            file->y += 1;
        }
    }
}

void find_my_square(BSQ *file)
{
    file->y = 2;
    file->x = 1;
    file->biggest_size = 0;

    execute_square_loop(file);

}
