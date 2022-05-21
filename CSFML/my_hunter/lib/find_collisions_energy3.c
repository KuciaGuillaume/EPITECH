/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** find_collisions_energy2.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include <SFML/Audio.h>

void restart_energy_3(frm_t *frm, btn *btns)
{
    if (((rand() % (1 - 0 + 1)) + 0) == 1) {
        btns[14].offset.x = 1800;
        btns[14].move = (-3) * frm->speed_vector;
    } else {
        btns[14].offset.x = 1;
        btns[14].move = 3 * frm->speed_vector;
    }
    btns[14].offset.y = (rand() % (600 - 200 + 1)) + 200;
    sfSprite_setPosition(btns[14].sprite, btns[14].offset);
    btns[14].status = (-1);
    if (frm->speed_vector < 2)
        frm->speed_vector += 1;
    frm->value_score += (1 * frm->speed_vector);
}

void calc_find_collisions_energy3(int *bullet_2, int *bullet_3, btn *btns)
{
    if ((bullet_2[0] >= btns[14].offset.x && bullet_2[0] <=
    btns[14].offset.x + btns[14].rect.width) &&
    (bullet_2[1] >= btns[14].offset.y && bullet_2[1] <=
    btns[14].offset.y + btns[14].rect.height)) {
        btns[14].status = 0;
        btns[11].move = 0;
        btns[11].offset = (sfVector2f){0, 0};
    }
    if ((bullet_3[0] >= btns[14].offset.x && bullet_3[0] <=
    btns[14].offset.x + btns[14].rect.width) &&
    (bullet_3[1] >= btns[14].offset.y && bullet_3[1] <=
    btns[14].offset.y + btns[14].rect.height)) {
        btns[14].status = 0;
        btns[12].move = 0;
        btns[12].offset = (sfVector2f){0, 0};
    }
}

void find_collisions_energy3(frm_t *frm, btn *btns)
{
    int bullet_1[] =
    {btns[10].offset.x, btns[10].offset.y};
    int bullet_2[] =
    {btns[11].offset.x, btns[11].offset.y};
    int bullet_3[] =
    {btns[12].offset.x, btns[12].offset.y};

    if ((bullet_1[0] >= btns[14].offset.x && bullet_1[0] <=
    btns[14].offset.x + btns[14].rect.width) &&
    (bullet_1[1] >= btns[14].offset.y && bullet_1[1] <=
    btns[14].offset.y + btns[14].rect.height)) {
        btns[14].status = 0;
        btns[10].move = 0;
        btns[10].offset = (sfVector2f){0, 0};
    }
    calc_find_collisions_energy3(bullet_2, bullet_3, btns);
    if (btns[14].status == 0)
        restart_energy_3(frm, btns);
}