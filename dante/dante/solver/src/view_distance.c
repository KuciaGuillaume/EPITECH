/*
** EPITECH PROJECT, 2021
** solver
** File description:
** view_distance.c
*/

#include "my.h"

int get_begin_distance(opt_t *opt, i2f ap, char dir)
{
    int pos = cvt_to_hard(ap.x, ap.y, opt);

    if (dir == '>')
        opt->v_path[pos] = opt->v_path[pos - 1] + 1;
    if (dir == '<')
        opt->v_path[pos] = opt->v_path[pos + 1] + 1;
    if (dir == 'z')
        opt->v_path[pos] = opt->v_path[pos + opt->ln] + 1;
    if (dir == 's')
        opt->v_path[pos] = opt->v_path[pos - opt->ln] + 1;
    return opt->v_path[pos];
}

void view_distance(i2f ap, opt_t *opt, char dir)
{
    int pos = cvt_to_hard(ap.x, ap.y, opt);
    int height = 0;
    int weight = 0;
    int distance = 0;

    height = (ap.y <= opt->end.y) ? (opt->end.y - ap.y) : (ap.y - opt->end.y);
    weight = (ap.x <= opt->end.x) ? (opt->end.x - ap.x) : (ap.x - opt->end.x);
    distance = (height + weight) * 2;
    distance += get_begin_distance(opt, ap, dir);
    new_node(opt, distance, (i2f){ap.x, ap.y});
    opt->v_maze[pos] = distance;
}
