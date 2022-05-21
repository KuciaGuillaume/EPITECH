/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** move_this.c
*/

#include "my.h"

int collisions_x(sokoban_t *sokoban, char e, int x, int i)
{
    if (sokoban->map[i] == e && sokoban->map[i + x] != '#') {
        if (sokoban->map[i + x] == 'X' && sokoban->map[i + x + x] != ' ' &&
        sokoban->map[i + x + x] != 'O')
            return 1;
        if (sokoban->map[i + x] == 'X')
            sokoban->map[i + x + x] = 'X';
        sokoban->map[i + x] = 'P';
        sokoban->map[i] = ' ';
        return 1;
    }
    return 0;
}

int collisions_y(sokoban_t *sokoban, char e, int dir, int i)
{
    if (sokoban->map[i] == e && sokoban->map[i - dir] != '#') {
        if (sokoban->map[i - dir] == 'X' && sokoban->map[i - (dir * 2)] !=
        ' ' && sokoban->map[i - (dir * 2)] != 'O')
            return 1;
        if (sokoban->map[i - dir] == 'X')
            sokoban->map[i - (dir * 2)] = 'X';
        sokoban->map[i] = ' ';
        sokoban->map[i - dir] = e;
        return 1;
    }
    return 0;
}

void move_this_x(sokoban_t *sokoban, char e, int x)
{
    for (int i = 0; sokoban->map[i] != '\0'; i++) {
        if (collisions_x(sokoban, e, x, i) == 1)
            return;
    }
}

void move_this_y(sokoban_t *sokoban, char e, int x)
{
    int line = 0;

    for (; sokoban->map[line] != '\n'; line++);
    line += 1;
    for (int i = 0; sokoban->map[i] != '\0'; i++) {
        if (collisions_y(sokoban, e, (line * x), i) == 1)
            return;
    }
}
