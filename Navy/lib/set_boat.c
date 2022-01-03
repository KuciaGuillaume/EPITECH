/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** set_boat
*/

#include "../include/my.h"

void find_x1(char *map, boat_t *size)
{
    static int e = 0;

    for (int i = 0; map[i] != size->charx1; i++)
        size->x1 += 1;
}

void find_x2(char *map, boat_t *size)
{
    static int e = 0;

    for (int i = 0; map[i] != size->charx2; i++)
        size->x2 += 1;
}

void get_conditionnal(char *map, int i, boat_t *size)
{
    if (size->col >= size->y1 && size->col <= size->y2) {
        if (size->size_ligne >= size->x1 &&
        size->size_ligne <= size->x2 && map[i] == '.')
            map[i] = size->name_boat;
    }
}

void add_boat(char *map, char *pos, int i, boat_t size)
{
    size.col = 0;
    size.charx1 = pos[i];
    size.charx2 = pos[i + 3];
    size.x1 = 0;
    size.x2 = 0;
    find_x1(map, &size);
    find_x2(map, &size);
    size.y1 = pos[i + 1] - 48;
    size.y2 = pos[i + 4] - 48;

    for (i = 0; map[i]; i++) {
        get_conditionnal(map, i, &size);
        if (map[i] != '\n') {
            size.size_ligne += 1;
        } else {
            size.size_ligne = 0;
            size.col = map[i + 1] - 48;
        }
    }
}

void set_boat(char *map, char *pos)
{
    int i = 0;
    int e = 0;
    boat_t size;

    size.size_name_boat = 0;
    size.name_boat = pos[size.size_name_boat];
    for (; i < 32; i++) {
        if (pos[i] >= 'A' && pos[i] <= 'H') {
            add_boat(map, pos, i, size);
            for (; pos[i] != '\n' && pos[i] != '\0'; i++);
            size.name_boat = size.size_name_boat + 8 < 27 ?
            pos[size.size_name_boat += 8] : size.name_boat;
        }
    }
}
