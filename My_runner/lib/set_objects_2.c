/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** set_objects_2.c
*/

#include "../include/my.h"

void set_objects_2_2(node_t **node)
{
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "07_Forest.png", (init_t){1, (sfVector2f){5760, 1080}, (sfIntRect){0, 0,
    0, 0}, (sfVector2f){0, 0}, 0.01, -1920, (sfVector2f){1, 1}, 0, 0, 0, 0},
    node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "08_Forest.png", (init_t){1, (sfVector2f){5760, 1080}, (sfIntRect){0, 0,
    0, 0}, (sfVector2f){0, 0}, 0.03, -1920, (sfVector2f){1, 1}, 0, 0, 0, 0},
    node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "09_Forest.png", (init_t){1, (sfVector2f){5760, 1080}, (sfIntRect){0, 0,
    0, 0}, (sfVector2f){0, 0}, 0.05, -1920, (sfVector2f){1, 1}, 0, 0, 0, 0},
    node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "10_Sky.png", (init_t){1, (sfVector2f){5760, 1080}, (sfIntRect){0, 0, 0,
    0}, (sfVector2f){0, 0}, 0.07, -1920, (sfVector2f){1, 1}, 0, 0, 0, 0},
    node);
}

void set_objects_2_1(node_t **node)
{
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "02_Bushes.png", (init_t){1, (sfVector2f){5760, 1080}, (sfIntRect)
    {0, 0, 0, 0}, (sfVector2f){0, 0}, 0.001, -1920, (sfVector2f){1, 1}, 0, 0,
    0, 0},
    node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "04_Forest.png", (init_t){1, (sfVector2f){5760, 1080}, (sfIntRect){0, 0,
    0, 0}, (sfVector2f){0, 0}, 0.005, -1920, (sfVector2f){1, 1}, 0, 0, 0, 0},
    node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "05_Particles.png", (init_t){1, (sfVector2f){5760, 1080}, (sfIntRect){0,
    0, 0, 0}, (sfVector2f){0, 0}, 0.007, -1920, (sfVector2f){1, 1}, 0, 0, 0,
    0}, node);
    create_object_push_it_to_list("lib/Assets/Parallax_Background/"
    "06_Forest.png", (init_t){1, (sfVector2f){5760, 1080}, (sfIntRect){0, 0,
    0, 0}, (sfVector2f){0, 0}, 0.009, -1920, (sfVector2f){1, 1}, 0, 0, 0, 0},
    node);
    set_objects_2_2(node);
}
