/*
** EPITECH PROJECT, 2021
** Nouvelles_algo
** File description:
** replace_my_map.c
*/

#include "include/my.h"

void replace_my_map(BSQ *file, int x, int y, int i)
{
    if (file->buffer[i] == '.')
        file->map_array[y][x] = 1;
    if (file->buffer[i] == 'o')
        file->map_array[y][x] = 0;
}
