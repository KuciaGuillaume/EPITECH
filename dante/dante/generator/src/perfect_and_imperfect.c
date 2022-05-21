/*
** EPITECH PROJECT, 2021
** generator
** File description:
** perfect_and_imperfect.c
*/

#include "gen.h"

void perfect_and_imperfect(gen_t *gen, int y, bool wall)
{
    int lower = 1;
    int upper = gen->size_x;
    int num = 0;
    int position;

    if (!wall)
        return;
    num = (rand() % (upper - lower + 1)) + lower;

    if (gen->type == PERFECT)
        num = 1;
    for (; num != 0; num--) {
        position = (rand() % ((upper - 1) - lower + 1)) + lower;
        gen->maze[y][position] = '*';
    }
}
