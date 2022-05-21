/*
** EPITECH PROJECT, 2021
** dante
** File description:
** init_option.c
*/

#include "my.h"

void init_loop(char *maze, int i, opt_t *opt, int full)
{
    for (; maze[i] != '\0'; i++) {
        if (maze[i] == '\n') {
            opt->size.height++;
            opt->v_maze[i] = -10;
            opt->v_path[i] = -10;
        } else {
            opt->v_maze[i] = -5;
            opt->v_path[i] = 0;
        }
        opt->size.height == 0 ? opt->size.width++ : 0;
    }
    opt->v_maze[full] = -90;
    opt->v_path[full] = -90;
    opt->v_path[0] = 0;
}

opt_t init_opt(char *maze, opt_t opt, int full)
{
    int i = 0;

    opt.size = (v2f){0, 0, full};
    opt.begin = (i2f){0, 0};
    opt.actualp = (i2f){0, 0};
    opt.solved = false;
    opt.list = NULL;
    opt.v_maze = malloc(sizeof(int) * (full + 1));
    opt.v_path = malloc(sizeof(int) * (full + 1));
    init_loop(maze, i, &opt, full);
    opt.size.height++;
    opt.ln = opt.size.width + 1;
    opt.end = (i2f){opt.size.width, opt.size.height};
    if (opt.size.height <= 1 || opt.size.width <= 1) {
        free(opt.v_maze);
        free(maze);
        exit_msg("The given maze is too small."
        " Please provide a minimum maze size of 2*2.\n", 84);
    }
    return opt;
}
