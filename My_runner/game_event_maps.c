/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** game_event_maps.c
*/

#include "include/my.h"

int game_event_maps_2(window_t *window, sfEvent *event, node_t *node)
{
    if ((event->key.code == sfKeyNum1 || event->key.code == sfKeyNumpad1)) {
        window->difficulty = 1;
        window->filepath_score = "lib/Assets/Contents/map_score.txt";
        window->filepath_map = "map.txt";
        destroy_reset(node, window, 0);
        return 84;
    }
    if ((event->key.code == sfKeyNum4 || event->key.code == sfKeyNumpad4)) {
        window->difficulty = 20;
        window->filepath_score = "lib/Assets/Contents/World_of_Speed_"
        "score.txt";
        window->filepath_map = "lib/Assets/Contents/World_of_Speed.txt";
        destroy_reset(node, window, 0);
        return 84;
    }
    return 0;
}

int game_event_maps(window_t *window, sfEvent *event, node_t *node)
{
    if (window->button.home_map != 1 || window->MENU != 0 ||
    event->type != sfEvtKeyPressed)
        return 0;
    if ((event->key.code == sfKeyNum3 || event->key.code == sfKeyNumpad3)) {
        window->difficulty = 10;
        window->filepath_score = "lib/Assets/Contents/Cavern_score.txt";
        window->filepath_map = "lib/Assets/Contents/Cavern.txt";
        destroy_reset(node, window, 0);
        return 84;
    }
    if ((event->key.code == sfKeyNum2 || event->key.code == sfKeyNumpad2)) {
        window->difficulty = 8;
        window->filepath_score = "lib/Assets/Contents/Mountains_score.txt";
        window->filepath_map = "lib/Assets/Contents/Mountains.txt";
        destroy_reset(node, window, 0);
        return 84;
    }
    return game_event_maps_2(window, event, node);
}
