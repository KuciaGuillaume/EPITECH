/*
** EPITECH PROJECT, 2021
** solver
** File description:
** move_to_min.c
*/

#include "my.h"

i2f find_min(opt_t *opt, char *maze)
{
    i2f min = (i2f){0, 0};
    list_t *start = opt->list;
    int pos = 0;
    int value = __INT_MAX__;

    for (; opt->list != NULL; opt->list = opt->list->previous) {
        pos = cvt_to_hard(opt->list->node.pos.x, opt->list->node.pos.y, opt);
        if (opt->list->node.val < value && maze[pos] != 'Q' &&
        maze[pos] != '<' && maze[pos] != '>' && maze[pos] != 'z' &&
        maze[pos] != 's') {
            value = opt->list->node.val;
            min = opt->list->node.pos;
        }
    }
    opt->list = start;
    return min;
}

void move_to_min_up_and_down(opt_t *opt, char *maze, int min, int pos)
{
    if (min == pos + opt->ln || maze[min - opt->ln] == 'z' || \
    maze[min - opt->ln] == '<' || maze[min - opt->ln] == '>') {
        maze[min] = 'z';
        return;
    }
    if (min == pos - opt->ln || maze[min + opt->ln] == 's' || \
    maze[min + opt->ln] == '<' || maze[min + opt->ln] == '>') {
        maze[min] = 's';
        return;
    }
    exit_msg("no solution found", 0);
}

void move_to_min(opt_t *opt, char *maze)
{
    int pos = cvt_to_hard(opt->actualp.x, opt->actualp.y, opt);
    i2f imin = find_min(opt, maze);
    int min = cvt_to_hard(imin.x, imin.y, opt);

    opt->actualp = imin;
    if (min == pos + 1  || maze[min - 1] == '<' || \
    maze[min - 1] == 'z' || maze[min - 1] == 's') {
        maze[min] = '<';
        return;
    }
    if (min == pos - 1 || maze[min + 1] == '>' || \
    maze[min + 1] == 'z' || maze[min + 1] == 's') {
        maze[min] = '>';
        return;
    }
    move_to_min_up_and_down(opt, maze, min, pos);
}
