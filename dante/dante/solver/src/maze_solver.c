/*
** EPITECH PROJECT, 2021
** dante
** File description:
** maze_solver.c
*/

#include "my.h"
#include <stdlib.h>

void maze_solver(char *maze, int full)
{
    opt_t opt = init_opt(maze, opt, full);
    check_point(&opt, maze, full);
    int actual = 0;

    maze[0] = 'z';
    new_node(&opt, 0 + opt.v_path[0], (i2f){0, 0});
    for (int i = 0; !opt.solved; i++) {
        check_arround(&opt, maze);
        move_to_min(&opt, maze);
        cvt_to_hard(opt.end.x, opt.end.y, &opt);
        actual = cvt_to_hard(opt.actualp.x, opt.actualp.y, &opt);
        if (actual == (full - 1)) {
            print_path(maze, &opt);
            Close;
        }
    }
}
