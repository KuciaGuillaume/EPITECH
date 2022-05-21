/*
** EPITECH PROJECT, 2021
** solver
** File description:
** print_path.c
*/

#include "my.h"

void vertical_path(char *maze, int *pos, int *a, opt_t *opt)
{
    if ((maze[*pos - opt->ln] == 'z' || maze[*pos - opt->ln] == '<' ||
    maze[*pos - opt->ln] == '>') && *a == 0) {
        maze[*pos] = 'o';
        *pos -= opt->ln;
        *a += 1;
    }
    if ((maze[*pos + opt->ln] == 's' || maze[*pos + opt->ln] == '<' ||
    maze[*pos + opt->ln] == '>') && *a == 0) {
        maze[*pos] = 'o';
        *pos += opt->ln;
        *a += 1;
    }
}

void horizontal_path(char *maze, int *pos, int *a)
{
    if ((maze[*pos - 1] == '<' || maze[*pos - 1] == 'z' ||
    maze[*pos - 1] == 's') && *a == 0) {
        maze[*pos] = 'o';
        *pos -= 1;
        *a += 1;
    }
    if ((maze[*pos + 1] == '>' || maze[*pos + 1] == 'z' ||
    maze[*pos + 1] == 's') && *a == 0) {
        maze[*pos] = 'o';
        *pos += 1;
        *a += 1;
    }
}

void go_to_begin_point(opt_t *opt, char *maze, i2f ap)
{
    int pos = cvt_to_hard(ap.x, ap.y, opt);
    int a = 0;

    for (; pos != 0; ) {
        a = 0;
        horizontal_path(maze, &pos, &a);
        vertical_path(maze, &pos, &a, opt);
    }
}

void print_path(char *maze, opt_t *opt)
{
    opt->end.x -= 1;
    go_to_begin_point(opt, maze, opt->end);
    maze[0] = 'o';
    for (int i = 0; i != opt->size.full; i++) {
        if (maze[i] != 'o' && maze[i] != 'X' && maze[i] != '\n')
            maze[i] = '*';
        put("%c", maze[i]);
    }
}
