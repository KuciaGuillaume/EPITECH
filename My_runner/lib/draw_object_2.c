/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** draw_object_2.c
*/

#include "../include/my.h"

void draw_object_3(window_t *window, node_t *node)
{
    if (window->MENU == 0 && node->value->value.type == 6
    && node->value->value.identity_type == 7 ) {
        sfRenderWindow_drawSprite(window->window, node->value->sprite, NULL);
        node->value->value.is_drawing = 1;
    }
    if (window->MENU == 0 && node->value->value.type == 6
    && node->value->value.identity_type == 8 && window->button.home_map == 1) {
        sfRenderWindow_drawSprite(window->window, node->value->sprite, NULL);
        node->value->value.is_drawing = 1;
    }
}

void draw_object_2(window_t *window, node_t *node)
{
    if (((window->MENU == 1 && node->value->value.type == 6
    && node->value->value.identity_type < 2) || (window->MENU == 1 &&
    node->value->value.type == 6 && node->value->value.identity_type != 2 &&
    window->end_game == 1)) && node->value->value.identity_type != 7 &&
    node->value->value.identity_type != 8) {
        sfRenderWindow_drawSprite(window->window, node->value->sprite, NULL);
        node->value->value.is_drawing = 1;
    }
    if (window->MENU == 1 && node->value->value.type == 6
    && node->value->value.identity_type == 2 &&
    window->button.game_play == 0) {
        sfRenderWindow_drawSprite(window->window, node->value->sprite, NULL);
        node->value->value.is_drawing = 1;
    }
    draw_object_3(window, node);
}
