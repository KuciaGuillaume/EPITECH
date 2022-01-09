/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** jump.c
*/

#include "../include/my.h"

void jump_4(window_t *window, node_t *node)
{
    if (window->fly == 0) {
        node->value->value.offset.y += window->statics.jump_drop;
        window->statics.jump_drop += 0.05;
    } else if (window->double_JUMP == 1)
        node->value->value.offset.y += 0.8;
    else {
        node->value->value.offset.y += window->statics.jump_drop;
        window->statics.jump_drop += 0.05;
    }
}

void jump_3(window_t *window, node_t *node)
{
    if (node->value->value.offset.y >= window->perso.offset.y - 40) {
        node->value->value.offset.y = window->perso.offset.y - 40;
        window->JUMMODE = 0;
        window->double_JUMP = 0;
        window->statics.jump_a = 0;
        window->statics.jump_up = 12;
        window->statics.jump_drop = 0.09;
    } else
        jump_4(window, node);
}

void jump_2(window_t *window, node_t *node)
{
    if (window->double_JUMP == 1) {
        window->jump_up = 290;
    } else
        window->jump_up = 220;

    if (window->statics.jump_e == 0) {
        window->statics.jump_e = 1;
    }
    if (window->JUMMODE == 1 && window->statics.jump_a == 0) {
        node->value->value.offset.y -= window->statics.jump_up;
        if (window->statics.jump_up - 1.5 > 0)
            window->statics.jump_up -= 1.5;
    }
}

void jump(window_t *window, node_t *node)
{
    if (window->MENU == 0)
        return;
    jump_2(window, node);
    if (node->value->value.offset.y <= window->perso.offset.y -
    window->jump_up)
        window->statics.jump_a = 1;
    if (window->statics.jump_a == 1) {
        jump_3(window, node);
        if (window->statics.get_collisions_nothing == 2)
            node->value->value.offset.x -= (window->speed - 0.1) * (-1);
    }
}
