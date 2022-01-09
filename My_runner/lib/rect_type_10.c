/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** rect_type_10.c
*/

#include "../include/my.h"

void rect_type_10_3(node_t *node, window_t *window)
{
    if (window->button.home_map == 1 && node->value->value.type == 6 &&
    node->value->value.identity_type == 7) {
        node->value->value.rect.left = node->value->value.rect.width;
    } else if (node->value->value.type == 6 &&
    node->value->value.identity_type == 7)
        node->value->value.rect.left = 0;
    if (node->value->value.type == 6 &&
    node->value->value.identity_type == 8) {
        if (my_strcmp("map.txt", window->filepath_map) == 0)
            node->value->value.rect.left = 0;
        if (my_strcmp("lib/Assets/Contents/Mountains.txt",
        window->filepath_map) == 0)
            node->value->value.rect.left = 1887.5;
        if (my_strcmp("lib/Assets/Contents/Cavern.txt",
        window->filepath_map) == 0)
            node->value->value.rect.left = 3775;
        if (my_strcmp("lib/Assets/Contents/World_of_Speed.txt",
        window->filepath_map) == 0)
            node->value->value.rect.left = 5662;
    }
}

void rect_type_10_2(node_t *node, window_t *window)
{
    if (window->button.back_to_menu == 1 && node->value->value.type == 6 &&
    node->value->value.identity_type == 5) {
        node->value->value.rect = (sfIntRect){324, 0, 324, 62};
    } else if (node->value->value.type == 6 &&
    node->value->value.identity_type == 5) {
        node->value->value.rect = (sfIntRect){0, 0, 324, 62};
    }
    if (window->button.REPLAY == 1 && node->value->value.type == 6 &&
    node->value->value.identity_type == 6) {
        node->value->value.rect = (sfIntRect){324, 0, 324, 62};
    } else if (node->value->value.type == 6 &&
    node->value->value.identity_type == 6) {
        node->value->value.rect = (sfIntRect){0, 0, 324, 62};
    }
    rect_type_10_3(node, window);
}

void rect_type_10(node_t *node, window_t *window)
{
    if (window->button.PLAY == 1 && node->value->value.type == 10) {
        node->value->value.rect.left = 308;
    } else if (node->value->value.type == 10) {
        node->value->value.rect.left = 0;
    }
    if (window->button.quit_score == 1 && node->value->value.type == 6 &&
    node->value->value.identity_type == 4) {
        node->value->value.rect = (sfIntRect){60, 0, 208, 60};
        sfSprite_setPosition(node->value->sprite, (sfVector2f){1207, 191});
        node->value->value.offset = (sfVector2f){1207, 191};
        window->statics.get_rect_type_10 = 0;
    } else if (node->value->value.type == 6 &&
    node->value->value.identity_type == 4) {
        node->value->value.rect = (sfIntRect){0, 0, 60, 60};
        if (window->statics.get_rect_type_10 == 1) {
            sfSprite_setPosition(node->value->sprite, (sfVector2f){1355, 191});
            node->value->value.offset = (sfVector2f){1355, 191};
        }
        window->statics.get_rect_type_10 = 1;
    }
    rect_type_10_2(node, window);
}
