/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** intersection.c
*/

#include "../include/my.h"

void intersection_rect_10(window_t *window, node_t *node, float seconds)
{
    if ((node->value->value.type == 10 ||
    node->value->value.type == 6) && seconds >= node->value->value.speed) {
        rect_type_10(node, window);
        sfClock_restart(node->value->clock);
    }
}

void intersection_rect(window_t *window, node_t *node, sfTime time)
{
    if (node->value->value.type == 3)
        window->perso.info_pos = sfSprite_getPosition(node->value->sprite);
    if (node->value->value.type == 3 && time.microseconds >= 10000)
        jump(window, node);
}

void intersection(window_t *window, node_t *node)
{
    if (node->value->value.type == 2 && (node->value->value.identity_type == 15
    || node->value->value.identity_type == 16))
        get_collisions_nothing(window, node);
    if (node->value->value.type == 2 && node->value->value.identity_type == 5)
        get_collisions_large_spike(window, node);
}
