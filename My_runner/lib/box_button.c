/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** box_button.c
*/

#include "../include/my.h"

int box_active(node_t *node, window_t *window)
{
    sfVector2i offset;
    offset = sfMouse_getPositionRenderWindow(window->window);

    if (offset.x >= node->value->value.offset.x &&
    offset.x <= node->value->value.offset.x +
    node->value->value.rect.width && offset.y >=
    node->value->value.offset.y && offset.y <=
    node->value->value.offset.y +
    node->value->value.rect.height)
        return 1;
    return 0;
}

void box_button_3(node_t *node, window_t *window)
{
    if (node->value->value.type == 6 &&
    node->value->value.identity_type == 7 &&
    node->value->value.is_drawing == 1 &&
    window->MENU == 0) {
        if (box_active(node, window) == 1)
            window->button.home_map = 1;
        else
            window->button.home_map = 0;
    }
}

void box_button_2(node_t *node, window_t *window)
{
    if (node->value->value.type == 6 &&
    node->value->value.identity_type == 5 &&
    node->value->value.is_drawing == 1 &&
    window->MENU == 1) {
        if (box_active(node, window) == 1)
            window->button.back_to_menu = 1;
        else
            window->button.back_to_menu = 0;
    }
    if (node->value->value.type == 6 &&
    node->value->value.identity_type == 6 &&
    node->value->value.is_drawing == 1) {
        if (box_active(node, window) == 1)
            window->button.REPLAY = 1;
        else
            window->button.REPLAY = 0;
    }
    box_button_3(node, window);
}

void box_button(node_t *node, window_t *window)
{
    if (node->value->value.type == 10 && window->MENU == 0) {
        if (box_active(node, window) == 1)
            window->button.PLAY = 1;
        else
            window->button.PLAY = 0;
    }
    if (node->value->value.type == 6 &&
    node->value->value.identity_type == 4 &&
    node->value->value.is_drawing == 1) {
        if (box_active(node, window) == 1)
            window->button.quit_score = 1;
        else
            window->button.quit_score = 0;
    }
    box_button_2(node, window);
}
