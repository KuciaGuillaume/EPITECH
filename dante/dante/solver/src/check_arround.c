/*
** EPITECH PROJECT, 2021
** solver
** File description:
** check_arround.c
*/

#include "my.h"

void check_arround_right_and_left(int right, int left, opt_t *opt, char *maze)
{
    if (right <= opt->size.full)
        if (maze[right] == '*' && opt->v_maze[right] == -5 && \
        right < opt->size.full)
            view_distance((i2f){opt->actualp.x + 1, opt->actualp.y}, \
            opt, '>');
    if (left >= 0)
        if (maze[left] == '*' && opt->v_maze[left] == -5 && \
        left > 0)
            view_distance((i2f){opt->actualp.x - 1, opt->actualp.y}, \
            opt, '<');
}

void check_arround(opt_t *opt, char *maze)
{
    int actualp = cvt_to_hard(opt->actualp.x, opt->actualp.y, opt);
    int up = actualp - opt->ln;
    int down = actualp + opt->ln;
    int right = actualp + 1;
    int left = actualp - 1;

    if (up >= 0)
        if (maze[up] == '*' && opt->v_maze[up] == -5 && up > 0)
            view_distance((i2f){opt->actualp.x, opt->actualp.y - 1}, \
            opt, 'z');
    if (down <= opt->size.full)
        if (maze[down] == '*' && opt->v_maze[down] == -5 && \
        down < opt->size.full)
            view_distance((i2f){opt->actualp.x, opt->actualp.y + 1}, \
            opt, 's');
    check_arround_right_and_left(right, left, opt, maze);
}
