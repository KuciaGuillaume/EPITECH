/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** move_type1-2.c
*/

#include "../include/my.h"

void move_type1_2(node_t *node, window_t *window)
{
    sfVector2f offset;
    offset = sfSprite_getPosition(node->value->sprite);
    if (offset.x <= node->value->value.reset) {
        if (offset.x <= node->value->value.reset &&
        node->value->value.type == 2) {
            sfSprite_setPosition(node->value->sprite, (sfVector2f)
            {window->spawn_reset, node->value->value.offset.y});
        } else {
            sfSprite_setPosition(node->value->sprite,
            node->value->value.offset);
        }
    }
    if ((node->value->value.type == 2 && window->MENU == 1))
        sfSprite_move(node->value->sprite, (sfVector2f){(window->speed), 0});
    else if (window->MENU == 1 || node ->value->value.type == 4)
        sfSprite_move(node->value->sprite, (sfVector2f){(-1), 0});
    sfClock_restart(node->value->clock);
}
