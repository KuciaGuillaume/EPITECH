/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_opt_btn.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void active_energy_animation(frm_t *frm, btn *btns)
{
    if (frm->seconds_energy > 0.05) {
        if (btns[9].rect.left == btns[9].size_width - btns[9].rect.width) {
            btns[9].rect.left = 0;
            btns[13].rect.left = 0;
            btns[14].rect.left = 0;
        } else {
            btns[9].rect.left += btns[9].rect.width;
            btns[13].rect.left += btns[13].rect.width;
            btns[14].rect.left += btns[14].rect.width;
        }
        sfClock_restart(frm->clock_energy);
    }
    if (frm->menu == 1) {
        set_move_energy(frm, btns);
        if (btns[13].status != 0 && btns[13].status != (-2))
            set_move_energy_13(frm, btns);
        if (btns[14].status != 0 && btns[14].status != (-2))
            set_move_energy_14(frm, btns);
    }
}

void active_background_move(frm_t *frm, btn *btns)
{
    sfSprite_setTextureRect(btns[7].sprite, btns[7].rect);
    if (frm->menu == 1 &&
    btns[7].rect.left < btns[7].size_width - btns[7].rect.width) {
        if (frm->seconds > 0.0001) {
            btns[7].rect.left += (2 * frm->speed_vector);
            sfClock_restart(frm->clock);
        }
    } else
        btns[7].rect.left = 0;
}

void set_opt_button(frm_t *frm, btn *btns)
{
    sfSprite_setTextureRect(btns[4].sprite, btns[4].rect);
    sfSprite_setTextureRect(btns[0].sprite, btns[0].rect);
    active_background_move(frm, btns);
    sfSprite_setTextureRect(btns[6].sprite, btns[6].rect);
    sfSprite_setTextureRect(btns[8].sprite, btns[8].rect);
    sfSprite_setTextureRect(btns[9].sprite, btns[9].rect);
    sfSprite_setTextureRect(btns[13].sprite, btns[13].rect);
    sfSprite_setTextureRect(btns[14].sprite, btns[14].rect);
    sfSprite_setTextureRect(btns[16].sprite, btns[16].rect);
}
