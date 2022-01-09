/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** get_collisions_nothing.c
*/

#include "../include/my.h"

void collisions_spike_active(window_t *window)
{
    if (window->life != 0) {
        if (window->statics.get_collisions_nothing == 1
        || window->statics.get_collisions_nothing == 2)
            window->life = 0;
        else
            window->life -= 1;
    }
    window->statics.get_collisions = 1;
}

void get_collisions_large_spike(window_t *window, node_t *node)
{
    sfVector2f offset;

    offset = sfSprite_getPosition(node->value->sprite);
    if ((window->perso.info_pos.x + 71 >= offset.x) &&
    (window->perso.info_pos.x + 71 <= offset.x + 620) &&
    (window->perso.info_pos.y + 64 >= offset.y - 77) &&
    (window->perso.info_pos.y + 64 <= offset.y + 200) &&
    window->MENU == 1 && window->statics.get_collisions == 0) {
        collisions_spike_active(window);
    } else if ((offset.x + 620 < window->perso.info_pos.x + 71)
    && (offset.x + 620 > ((window->perso.info_pos.x + 71) - 1)))
        window->statics.get_collisions = 0;
}

void collision_is_active(window_t *window, node_t *node)
{
    if (window->statics.nothing == 0 &&
    window->statics.get_collisions_nothing == 0
    && node->value->value.identity_type == 15) {
        window->perso.offset.y += node->value->value.down;
        window->statics.jump_a = 1;
        window->statics.get_collisions_nothing = 1;
    } else if (window->statics.nothing == 0 &&
    window->statics.get_collisions_nothing == 0
    && node->value->value.identity_type == 16) {
        if (window->JUMMODE != 1) {
            window->perso.offset.y = window->save_y +=
            (node->value->value.down * (-1));
            window->JUMMODE = 1;
        }
        if (window->double_JUMP != 1)
            window->double_JUMP = 1;
        if (window->fly == 1)
            window->fly = 0;
        window->statics.get_collisions_nothing = 1;
    }
}

void test_if_collisions(window_t *window, node_t *node, sfVector2f offset)
{
    if ((window->perso.info_pos.x + 71 >= offset.x) &&
    (window->perso.info_pos.x + 71 <= offset.x + 600) &&
    (window->perso.info_pos.y + 64 >= offset.y - 77) &&
    (window->perso.info_pos.y + 64 <= offset.y + 300) &&
    window->MENU == 1) {
        collision_is_active(window, node);
    } else if ((window->statics.get_collisions_nothing == 1 ||
    window->statics.get_collisions_nothing == 2) &&
    ((((window->perso.info_pos.x + 71) -
    (offset.x + 600) > 0) && ((window->perso.info_pos.x + 71) -
    (offset.x + 600) < 10)) || (((window->perso.info_pos.y + 64) -
    (offset.y + 300) > 0) && ((window->perso.info_pos.y + 64) -
    (offset.y + 300) < 10)))) {
        if (node->value->value.obstacles == 1)
            window->statics.get_collisions_nothing = 2;
        else
            window->statics.get_collisions_nothing = 0;
    }
}

void get_collisions_nothing(window_t *window, node_t *node)
{
    sfVector2f offset;

    offset = sfSprite_getPosition(node->value->sprite);
    if ((window->perso.info_pos.y + 64 > 1080 ||
    window->perso.info_pos.x + 71 < 0) && window->life > 0)
        window->life = 0;
    test_if_collisions(window, node, offset);
}
