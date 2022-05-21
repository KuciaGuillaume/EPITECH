/*
** EPITECH PROJECT, 2021
** dante
** File description:
** check_point.c
*/

#include "my.h"

void check_point(opt_t *opt, char *maze, int full)
{
    if (maze[full - 1] != '*') {
        free(opt->v_maze);
        free(maze);
        exit_msg("The exit point of the labyrinth is not good!"
        " It must be at the bottom right and must be a '*'.\n", 84);
    }
    if (maze[0] != '*') {
        free(opt->v_maze);
        free(maze);
        exit_msg("The starting point of the maze is not good!"
        " It must be in {0, 0} and must be a '*'.\n", 84);
    }
}
