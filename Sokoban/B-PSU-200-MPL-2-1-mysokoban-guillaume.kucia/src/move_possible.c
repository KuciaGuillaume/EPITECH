/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** move_possible.c
*/

#include "my.h"

int find_boxes(char *map)
{
    int boxes = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'X')
            boxes++;
    }
    return boxes;
}

void move_possible_loop(char *map, int *boxes, int line)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'X' && map[i - line] == '#' && map[i + 1] == '#') {
            *boxes -= 1;
            continue;
        }
        if (map[i] == 'X' && map[i + line] == '#' && map[i + 1] == '#') {
            *boxes -= 1;
            continue;
        }
        if (map[i] == 'X' && map[i - line] == '#' && map[i - 1] == '#') {
            *boxes -= 1;
            continue;
        }
        if (map[i] == 'X' && map[i + line] == '#' && map[i - 1] == '#') {
            *boxes -= 1;
            continue;
        }
    }
}

bool move_possible(char *map)
{
    int line = 0;
    int boxes = find_boxes(map);

    for (; map[line] != '\n'; line++);
    line += 1;
    move_possible_loop(map, &boxes, line);
    if (boxes <= 0)
        return false;
    return true;
}

int calc_line(char *str)
{
    int i = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    return i;
}

int calc_col(char *str)
{
    int e = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            e++;
    }
    return e;
}
