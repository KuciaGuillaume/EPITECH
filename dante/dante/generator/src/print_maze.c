/*
** EPITECH PROJECT, 2021
** generator
** File description:
** print_maze.c
*/

#include "gen.h"

void print_maze(gen_t *gen)
{
    for (int y = 0; y != gen->size_y; y++) {
        for (int x = 0; x != gen->size_x; x++)
            put("%c", gen->maze[y][x]);
        put("\n");
    }
}
