/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_gun_action.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void set_gun_shoot_calc(btn *btns)
{
    btns[6].rect.left += btns[6].rect.width;
    if (btns[10].move == 0)
        btns[10].move = 1;
    else if (btns[11].move == 0)
        btns[11].move = 1;
    else if (btns[12].move == 0)
        btns[12].move = 1;
}

void set_gun_shoot(frm_t *frm, sfEvent event, btn *btns)
{
    if (event.type == sfEvtMouseButtonPressed &&
    frm->Mouse_mode == 0 && frm->menu == 1) {
        if (btns[6].rect.left !=
        btns[6].size_width - btns[6].rect.width)
            set_gun_shoot_calc(btns);
    }
}

void set_gun_move(frm_t *frm, btn *btns)
{
    if (frm->mouse_pos.y >= 945) {
        frm->Mouse_mode = 1;
    } else if (frm->active != 3) {
        frm->Mouse_mode = 0;
        btns[2].offset.x = frm->mouse_pos.x - 16;
        btns[2].offset.y  = frm->mouse_pos.y - 16;
        sfSprite_setPosition(btns[2].sprite, btns[2].offset);
        if (frm->mouse_pos.x >= 20 &&
        frm->mouse_pos.x <= 1870) {
            btns[1].offset.x = frm->mouse_pos.x - 5;
            btns[1].offset.y = 700;
            sfSprite_setPosition(btns[1].sprite, btns[1].offset);
        }
    }
}

void set_play_gun_music(frm_t *frm, btn *btns)
{
    if (btns[6].rect.left !=
    btns[6].size_width - btns[6].rect.width) {
        sfMusic_stop(frm->gun_m);
        sfMusic_play(frm->gun_m);
        sfMusic_setVolume(frm->gun_m, 5.00);
    } else {
        sfMusic_stop(frm->no_bullet_m);
        sfMusic_play(frm->no_bullet_m);
    }
}

void set_gun_action(frm_t *frm, btn *btns)
{
    if (frm->menu == 1 && frm->mouse_pos.y < 945 &&
    (frm->Mouse_mode != 1 || frm->F8 == 1)) {
        set_play_gun_music(frm, btns);
    }
}
