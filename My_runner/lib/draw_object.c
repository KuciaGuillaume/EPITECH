/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** draw_object.c
*/

#include "../include/my.h"
#include <unistd.h>

void get_collisions(node_t *node, window_t *window)
{
    sfVector2f offset;

    intersection(window, node);
    if (node->value->value.identity_type != 2 &&
    node->value->value.identity_type != 4)
        return;
    offset = sfSprite_getPosition(node->value->sprite);
    if ((window->perso.info_pos.x + 71 >= offset.x) &&
    (window->perso.info_pos.x + 71 <= offset.x + 92) &&
    (window->perso.info_pos.y + 64 >= offset.y - 98) &&
    (window->perso.info_pos.y + 64 <= offset.y + 98) &&
    window->MENU == 1 && window->statics.get_collisions == 0) {
        if (window->life != 0)
            window->life -= 1;
        window->statics.get_collisions = 1;
    } else if (offset.x + 92 < window->perso.info_pos.x &&
    offset.x > (window->perso.info_pos.x - offset.x) - 50)
        window->statics.get_collisions = 0;
}

void rect_object(node_t *node, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(node->value->clock);
    float seconds = time.microseconds / 1000000.0;

    rect_life(window, node);
    if (window->button.game_play != 1 && node->value->value.type != 6 &&
    node->value->value.identity_type != 4)
        return;
    intersection_rect(window, node, time);
    if (node->value->value.rect.height != 0 ||
    node->value->value.rect.width != 0 || node->value->value.rect.left != 0 ||
    node->value->value.rect.top != 0) {
        sfSprite_setTextureRect(node->value->sprite, node->value->value.rect);
        if (node->value->value.type == 3 && time.microseconds >=
        node->value->value.speed) {
            rect_type_3(node, window);
            sfClock_restart(node->value->clock);
        }
        intersection_rect_10(window, node, seconds);
    }
}

void move_object(node_t *node, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(node->value->clock);
    float seconds = time.microseconds / 1000000.0;

    if ((node->value->value.type == 1 || node->value->value.type == 2 ||
    node->value->value.type == 4 ||
    node->value->value.type == 6) &&
    seconds > node->value->value.speed && node->value->value.speed != 0 &&
    window->button.game_play == 1)
        move_type1_2(node, window);
    if (node->value->value.type == 3 && seconds > 0.00009)
        sfSprite_setPosition(node->value->sprite, node->value->value.offset);
}

void draw_object(node_t *node, window_t *window)
{
    rect_object(node, window);
    move_object(node, window);
    get_collisions(node, window);
    node->value->value.is_drawing = 0;
    if (node->value->value.type == 2) {
        if (window->MENU == 1 && node->value->value.identity_type != 15
        && node->value->value.identity_type != 16) {
            sfRenderWindow_drawSprite(window->window, node->value->sprite,
            NULL);
            node->value->value.is_drawing = 1;
        }
    } else if (node->value->value.type < 5) {
        sfRenderWindow_drawSprite(window->window, node->value->sprite, NULL);
        node->value->value.is_drawing = 1;
    }
    if (window->MENU == 0 && (node->value->value.type == 5 ||
    node->value->value.type == 10)) {
        sfRenderWindow_drawSprite(window->window, node->value->sprite, NULL);
        node->value->value.is_drawing = 1;
    }
    draw_object_2(window, node);
}

void foreach(node_t *node, window_t *window, void (*pointer)(node_t *,
window_t *))
{
    while (node != NULL) {
        pointer(node, window);
        node = node->previous;
    }
}
