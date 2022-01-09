/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** create_object.c
*/

#include "../include/my.h"

void create_object_push_it_to_list(char *path_to_spritesheet, init_t value,
node_t **node)
{
    obj_t *object = malloc(sizeof(obj_t));
    object->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->value.size = value.size;
    object->value.rect = value.rect;
    object->value.offset = value.offset;
    object->value.speed = value.speed;
    object->value.type = value.type;
    object->clock = sfClock_create();
    object->value.reset = value.reset;
    object->value.down = value.down;
    object->value.obstacles = value.obstacles;
    object->value.identity_type = value.identity_type;
    sfSprite_setScale(object->sprite, value.scale);
    sfSprite_setPosition(object->sprite, value.offset);
    add_node(node, object);
}
