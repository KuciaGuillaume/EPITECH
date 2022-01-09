/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** load_map.c
*/

#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void set_assets(node_t **node, int e, char *map, offset_t *offsets)
{
    if (map[e] == '1') {
        create_object_push_it_to_list("lib/Assets/grass3.png", (init_t){2,
        (sfVector2f){offsets->x, offsets->y}, (sfIntRect){0, 300, 601, 300},
        (sfVector2f){offsets->x, offsets->y}, 0.0009, -600, (sfVector2f){1,
        1}, 1, 0, 0, 0}, node);
        offsets->z = 1;
    }
    if (map[e] == '2') {
        create_object_push_it_to_list("lib/Assets/Spikes/spike B.png",
        (init_t){2,
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0}, (sfVector2f)
        {offsets->x, offsets->y + 25}, 0.0009, -600, (sfVector2f){0.5, 0.5},
        2, 0, 0, 0}, node);
        offsets->z = 2;
    }
    set_assets_2(node, e, map, offsets);
}

void load_assets(node_t **node, int e, char *map, offset_t *offsets)
{

    if (map[e] != '\n') {
        offsets->x -= 600;
    } else {
        offsets->x = offsets->reset;
        offsets->y -= 100;
    }
    set_assets(node, e, map, offsets);
}

int set_spawn_reset(window_t *window, char *map)
{
    for (int i = 0; map[i] != '\n'; i += 1)
        window->spawn_reset += 600;
    if (window->spawn_reset < 2400) {
        my_putstr("Wrong input, you can try this [./my_runner -h]\n");
        my_putstr("Largeur de la map trop courte (Minimum : 5)\n");
        return 84;
    }
    return 0;
}

void initialise_x_and_y(int *e, offset_t *offsets, char *map)
{
    if (map[*e] != '\n') {
        offsets->x += 600;
    } else {
        offsets->reset = offsets->x;
        offsets->x = 0;
        offsets->y += 100;
    }
}

int load_map(node_t **node, char *filepath, window_t *window)
{
    offset_t offsets = {0, 0, 0, 0};
    char *map = "NULL";
    int fd = 0;
    int e = 0;
    int i = 0;

    fd = open(filepath, O_RDONLY);
    map = my_calloc(map, 20000);
    read(fd, map, 20000);
    for (; (map[i] >= '0' && map[i] <= '9') || map[i] == '\n'; i += 1);
    map[i] = '\0';
    if (set_spawn_reset(window, map) == 84)
        return 84;
    for (; e != i; e += 1)
        initialise_x_and_y(&e, &offsets, map);
    e -= 1;
    set_assets(node, e, map, &offsets);
    for (; e != 0; e -= 1)
        load_assets(node, e, map, &offsets);
    return 0;
}
