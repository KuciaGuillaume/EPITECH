/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** reset_perso.c
*/

#include "../include/my.h"

void reset_perso(node_t *node, window_t *window)
{
    sfSprite_setPosition(node->value->sprite, (sfVector2f)
    {window->perso.offset.x, (window->perso.offset.y - 40)});
    node->value->value.offset = (sfVector2f){window->perso.offset.x,
    (window->perso.offset.y - 40)};
    sfSprite_setScale(node->value->sprite, (sfVector2f){5, 5});
    node->value->value.scale = (sfVector2f){5, 5};
    sfSprite_setTextureRect(node->value->sprite, (sfIntRect){64, 40, 32, 35});
    node->value->value.rect = (sfIntRect){64, 40, 32, 35};
    node->value->value.speed = 80000;
}
