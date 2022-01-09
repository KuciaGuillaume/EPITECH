/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** rect_life.c
*/

#include "../include/my.h"

void rect_life(window_t *window, node_t *node)
{
    if (node->value->value.type == 6 &&
    node->value->value.identity_type == 1) {
        if (window->life == 3)
            node->value->value.rect.left = 669;
        if (window->life == 2)
            node->value->value.rect.left = 446;
        if (window->life == 1)
            node->value->value.rect.left = 223;
        if (window->life == 0) {
            node->value->value.rect.left = 0;
            window->life = -1;
        } else if (window->life < 0) {
            read_write_score(window);
            window->end_game = 1;
            window->button.game_play = 0;
        }
    }
}
