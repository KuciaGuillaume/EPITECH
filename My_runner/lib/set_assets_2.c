/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** set_assets_2.c
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int map_size(char *map)
{
    int i = 0;

    for (; map[i] != '\0'; i += 1);
    return i;
}

int find_line_size(char *map)
{
    int i = 0;

    for (; map[i] != '\n' && map[i] != '\0'; i += 1);
    return (i + 1);
}

int how_much_will_you_drop(int e, char *map)
{
    int line_size = find_line_size(map);
    int max_size = map_size(map);
    int drop = 200;

    if (e + line_size >= max_size)
        return drop;
    e += line_size;
    if (map[e] == '7' || map [e] == '6')
        drop -= 100;
    while (map[e] == '7') {
        drop += 100;
        e += line_size;
    }
    while (map[e] == '6') {
        drop += 50;
        e += line_size;
    }
    return drop;
}

void set_assets_nothing(node_t **node, int e, char *map, offset_t *offsets)
{
    int line_size = find_line_size(map);
    int max_size = map_size(map);
    int obstacles = 0;

    if (e + line_size >= max_size)
        return;
    if (e == 0 || map[e] == '\0')
        return;
    if (map[e] == '0' && map[e + 1] == '1')
        obstacles = 1;
    if ((map[e] == '0' && ((map[e - 1] == '1' && map[e + line_size] == '5') ||
    map[e + line_size] == '7' || map[e + line_size] == '6')) ||
    (map[e] == '0' && map[e - 1] == '0' && map[e + line_size] == '5' &&
    ((map[e + line_size + 1] == '5' || map[e + line_size + 1] == '1') &&
    (map[e + line_size - 1] == '1' || map[e + line_size - 1] == '5')))) {
        create_object_push_it_to_list("lib/Assets/grass3.png", (init_t){2,
        (sfVector2f){600, 200}, (sfIntRect){0, 300, 601, 200},
        (sfVector2f){offsets->x, offsets->y}, 0.0009, -600, (sfVector2f){1, 1},
        15, 0, how_much_will_you_drop(e, map), obstacles}, node);
        offsets->z = 1;
    }
}

void set_assets_2(node_t **node, int e, char *map, offset_t *offsets)
{
    if (map[e] == '4') {
        create_object_push_it_to_list("lib/Assets/Spikes/spike D.png",
        (init_t){2, (sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0}, (sfVector2f)
        {offsets->x, offsets->y + 25}, 0.0009, -600, (sfVector2f){0.5, 0.5},
        4, 0, 0, 0}, node);
        offsets->z = 2;
    }
    if (map[e] == '5') {
        create_object_push_it_to_list("lib/Assets/Spikes/spike A.png",
        (init_t){2, (sfVector2f){0, 0}, (sfIntRect){0, 0, 1180, 270},
        (sfVector2f){offsets->x, offsets->y + 25}, 0.0009, -600,
        (sfVector2f){0.5, 0.5}, 5, 0, 0, 0}, node);
        offsets->z = 2;
    }
    set_assets_nothing(node, e, map, offsets);
    set_assets_nothing_up(node, e, map, offsets);
}
