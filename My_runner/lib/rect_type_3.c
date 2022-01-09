/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** rect_type_3.c
*/

#include "../include/my.h"

void rect_top(node_t *node, window_t *window)
{
    if (window->JUMMODE == 1) {
        if (window->statics.get_rect_top == 0) {
            node->value->value.rect.left = 64;
            window->statics.get_rect_top = 1;
            node->value->value.rect.top = 75;
        }
    } else
        window->statics.get_rect_top = 0;
    if (window->double_JUMP == 1)
        window->statics.get_rect_top = 0;
}

void rect_type_3_menu(node_t *node, window_t *window)
{
    if (window->statics.get_rect_menu == 0) {
        node->value->value.rect.left = 10;
        node->value->value.rect.top = 0;
        node->value->value.rect.width = 40;
        node->value->value.rect.height = 40;
        sfSprite_setScale(node->value->sprite, (sfVector2f){13, 13});
        node->value->value.offset = (sfVector2f){1420, 450};
        sfSprite_setPosition(node->value->sprite, node->value->value.offset);
        window->statics.get_rect_menu = 1;
    } else {
        node->value->value.rect.left += 50;
    }
    if (node->value->value.rect.left >= 200)
        node->value->value.rect.left = 10;

}

void rect_type_3(node_t *node, window_t *window)
{
    if (window->MENU == 0) {
        rect_type_3_menu(node, window);
        return;
    }
    if (window->statics.get_rect == 0) {
        window->statics.get_rect = 1;
        reset_perso(node, window);
    }
    rect_top(node, window);
    if (node->value->value.rect.left >= 314) {
        if (node->value->value.rect.top == 75)
            node->value->value.rect.top = 40;
        node->value->value.rect.left = 64;
    } else {
        node->value->value.rect.left += 50;
    }
}
