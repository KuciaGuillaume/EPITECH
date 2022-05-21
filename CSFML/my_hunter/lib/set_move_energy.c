/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_move_energy.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void set_move_energy_14(frm_t *frm, btn *btns)
{
    btns[14].offset = sfSprite_getPosition(btns[14].sprite);
    if (btns[14].offset.x >= 1825 || btns[14].offset.x <= 0) {
        btns[16].rect.left += 234;
        btns[14].offset.x = (rand() % (1 - 0 + 1)) + 0;
        if (((rand() % (1 - 0 + 1)) + 0) == 1) {
            btns[14].offset.x = 1800;
            btns[14].move = ((-3) * frm->speed_vector);
        } else {
            btns[14].offset.x = 1;
            btns[14].move = (3 * frm->speed_vector);
        }
        btns[14].offset.y = (rand() % (600 - 200 + 1)) + 200;
        sfSprite_setPosition(btns[14].sprite, btns[14].offset);
    }
    sfSprite_move(btns[14].sprite, (sfVector2f){btns[14].move, 0});
}

void set_move_energy_13(frm_t *frm, btn *btns)
{
    btns[13].offset = sfSprite_getPosition(btns[13].sprite);
    if (btns[13].offset.x >= 1825 || btns[13].offset.x <= 0) {
        btns[16].rect.left += 234;
        btns[13].offset.x = (rand() % (1 - 0 + 1)) + 0;
        if (((rand() % (1 - 0 + 1)) + 0) == 1) {
            btns[13].offset.x = 1800;
            btns[13].move = ((-7) * frm->speed_vector);
        } else {
            btns[13].offset.x = 1;
            btns[13].move = (7 * frm->speed_vector);
        }
        btns[13].offset.y = (rand() % (600 - 200 + 1)) + 200;
        sfSprite_setPosition(btns[13].sprite, btns[13].offset);
    }
    sfSprite_move(btns[13].sprite, (sfVector2f){btns[13].move, 0});
}

void set_move_energy(frm_t *frm, btn *btns)
{
    btns[9].offset = sfSprite_getPosition(btns[9].sprite);
    if (btns[9].offset.x >= 1825 || btns[9].offset.x <= 0) {
        btns[16].rect.left += 234;
        btns[9].offset.x = (rand() % (1 - 0 + 1)) + 0;
        if (((rand() % (1 - 0 + 1)) + 0) == 1) {
            btns[9].offset.x = 1825;
            btns[9].move = (-5) * frm->speed_vector;
        } else {
            btns[9].offset.x = 1;
            btns[9].move = 5 * frm->speed_vector;
        }
        btns[9].offset.y = (rand() % (600 - 200 + 1)) + 200;
        sfSprite_setPosition(btns[9].sprite, btns[9].offset);
    }
    sfSprite_move(btns[9].sprite, (sfVector2f){btns[9].move, 0});
}