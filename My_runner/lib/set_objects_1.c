/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** set_objects_1.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void placement_character_by_the_map_2(node_t **node, char *map, int a,
window_t *window)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i != a; i += 1) {
        if (map[i] == '3') {
            create_object_push_it_to_list("lib/Assets/adventurer-sheet.png",
            (init_t){3, (sfVector2f){x, y}, (sfIntRect){64, 40, 32, 32},
            (sfVector2f){x, y}, 200000, 0, (sfVector2f){5, 5}, 3, 0, 0, 0},
            node);
            window->perso.offset.x = x;
            window->perso.offset.y = y;
        }
        x += 600;
        if (map[i] == '\n') {
            x = 0;
            y += 100;
        }
    }

}

int placement_character_by_the_map(node_t **node, char *filepath,
window_t *window)
{
    char *map = "NULL";
    int fd = 0;
    int i = 0;

    fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        my_putstr("Wrong input, you can try this [./my_runner -h]\n");
        my_putstr("Error while loading the map !\n");
        sfMusic_destroy(window->sound.background);
        return 84;
    }
    map = my_calloc(map, 20000);
    read(fd, map, 20000);
    for (; (map[i] >= '0' && map[i] <= '9') || map[i] == '\n'; i += 1);
    map[i] = '\0';
    placement_character_by_the_map_2(node, map, i, window);
    return 0;
}

int set_objects_3(node_t **node, char *filepath, window_t *window)
{
    create_object_push_it_to_list("lib/Assets/Play.png", (init_t){10,
    (sfVector2f){616, 127}, (sfIntRect){0, 0, 308, 127}, (sfVector2f)
    {18, 20}, 0, 0, (sfVector2f){1, 1}, 0, 0, 0, 0}, node);
    if (placement_character_by_the_map(node, filepath, window) == 84)
        return 84;
    create_object_push_it_to_list("lib/Assets/Menu.png", (init_t)
    {5, (sfVector2f){1920, 1080}, (sfIntRect){0, 0, 0, 0}, (sfVector2f)
    {0, 0}, 0, 0, (sfVector2f){1, 1}, 0, 0, 0, 0}, node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "01_Mist.png", (init_t){4, (sfVector2f){5760, 1080}, (sfIntRect){0, 0,
    0, 0}, (sfVector2f){0, 0}, 0.005, -1920, (sfVector2f){1, 1}, 0, 0, 0, 0},
    node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "03_Particles.png", (init_t){4, (sfVector2f){5760, 1080}, (sfIntRect){0,
    0, 0, 0}, (sfVector2f){0, 0}, 0.0001, -1920, (sfVector2f){1, 1}, 0, 0, 0,
    0}, node);
    return 0;
}

int set_objects_2(node_t **node, char *filepath, window_t *window)
{
    create_object_push_it_to_list("lib/Assets/end_score.png", (init_t){6,
    (sfVector2f){930, 698}, (sfIntRect){0, 0, 0, 0}, (sfVector2f){(960 - 465),
    (540 - 349)}, 0, 0, (sfVector2f){1, 1}, 3, 0, 0, 0}, node);
    create_object_push_it_to_list("lib/Assets/Life.png", (init_t){6,
    (sfVector2f){892, 122}, (sfIntRect){669, 0, 223, 122},
    (sfVector2f){1697, 0}, 0, 0, (sfVector2f){1, 1}, 1, 0, 0, 0}, node);
    create_object_push_it_to_list("lib/Assets/Pause.png", (init_t){6,
    (sfVector2f){512, 512}, (sfIntRect){0, 0, 0, 0}, (sfVector2f){(960 - 256),
    (540 - 256)}, 0, 0, (sfVector2f){1, 1}, 2, 0, 0, 0}, node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "01_Mist.png", (init_t){6, (sfVector2f){5760, 1080}, (sfIntRect){0, 0, 0,
    0}, (sfVector2f){0, 0}, 0.005, -1920, (sfVector2f){1, 1}, 0, 0, 0, 0},
    node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "03_Particles.png", (init_t){6, (sfVector2f){5760, 1080}, (sfIntRect)
    {0, 0, 0, 0}, (sfVector2f){0, 0}, 0.0001, -1920, (sfVector2f){1, 1}, 0,
    0, 0, 0}, node);
    return set_objects_3(node, filepath, window);
}

int set_objects_1(node_t **node, char *filepath, window_t *window)
{
    create_object_push_it_to_list("lib/Assets/maps.png", (init_t){6,
    (sfVector2f){7551, 787}, (sfIntRect){0, 0, 1887.5, 787},
    (sfVector2f){16.25, 206.5}, 0, 0, (sfVector2f){1, 1}, 8, 0, 0, 0}, node);
    create_object_push_it_to_list("lib/Assets/Home-Maps.png", (init_t){6,
    (sfVector2f){1014, 127}, (sfIntRect){0, 0, 507, 127},
    (sfVector2f){326, 20}, 0, 0, (sfVector2f){1, 1}, 7, 0, 0, 0}, node);
    create_object_push_it_to_list("lib/Assets/REPLAY.png", (init_t){6,
    (sfVector2f){648, 62}, (sfIntRect){0, 0, 324, 62},
    (sfVector2f){800, 788}, 0, 0, (sfVector2f){1, 1}, 6, 0, 0, 0}, node);
    create_object_push_it_to_list("lib/Assets/back_to_menu.png", (init_t){6,
    (sfVector2f){648, 62}, (sfIntRect){0, 0, 324, 62},
    (sfVector2f){800, 708}, 0, 0, (sfVector2f){1, 1}, 5, 0, 0, 0}, node);
    create_object_push_it_to_list("lib/Assets/quit_game(end_score).png",
    (init_t){6,
    (sfVector2f){268, 60}, (sfIntRect){0, 0, 60, 60},
    (sfVector2f){1355, 191}, 0, 0, (sfVector2f){1, 1}, 4, 0, 0, 0}, node);
    return set_objects_2(node, filepath, window);
}
