/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** set_assets_nothing_up.c
*/

#include "../include/my.h"

int how_much_will_you_up(int e, char *map)
{
    int line_size = find_line_size(map);
    int up = 0;

    if (e - line_size <= 0)
        return up;
    while (map[e] == '8') {
        up += 100;
        e -= line_size;
    }
    return up;
}

void set_assets_nothing_up(node_t **node, int e, char *map, offset_t *offsets)
{
    int line_size = find_line_size(map);

    if (e - line_size <= 0)
        return;
    if (map[e + line_size] == '8')
        return;
    if (e == 0 || map[e] == '\0')
        return;
    if (map[e] == '8') {
        create_object_push_it_to_list("lib/Assets/grass3.png", (init_t){2,
        (sfVector2f){600, 200}, (sfIntRect){0, 300, 601, 200},
        (sfVector2f){offsets->x, offsets->y}, 0.0009, -600, (sfVector2f){1, 1},
        16, 0, how_much_will_you_up(e, map), 0}, node);
        offsets->z = 1;
    }
}
