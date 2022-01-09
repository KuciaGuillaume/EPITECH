/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** destroy_object.c
*/

#include "../include/my.h"

void destroy_reset(node_t *node, window_t *window, int i)
{
    initiate_window(window);
    if (i == 1)
        window->MENU = 1;
    while (node->previous != NULL) {
        sfSprite_destroy(node->value->sprite);
        sfTexture_destroy(node->value->texture);
        sfClock_destroy(node->value->clock);
        node = node->previous;
    }
    node = NULL;
    set_objects_1(&node, window->filepath_map, window);
    load_map(&node, window->filepath_map, window);
    set_objects_2_1(&node);
    game_loop(window, node);
}

void destroy_object(node_t *node, window_t *window)
{
    while (node->previous != NULL) {
        sfSprite_destroy(node->value->sprite);
        sfTexture_destroy(node->value->texture);
        sfClock_destroy(node->value->clock);
        node = node->previous;
    }
    sfMusic_destroy(window->sound.background);
    sfText_destroy(window->score.best_score_text);
    sfText_destroy(window->score.score);
    sfRenderWindow_destroy(window->window);
}
