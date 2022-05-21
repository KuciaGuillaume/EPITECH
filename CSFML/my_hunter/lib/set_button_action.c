/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_btn_action.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void set_back_action(frm_t *frm, sfEvent event, btn *btns, text *dp)
{
    btns[8].rect.left = btns[8].rect.width;
    frm->Mouse_mode = 1;
    if (frm->sound_active == 0 && frm->F8 == 0) {
        sfMusic_play(frm->slide_m);
        frm->sound_active = 1;
    }
    if (event.type == sfEvtMouseButtonPressed && frm->F8 == 0) {
        sfMusic_stop(frm->tap_m);
        sfMusic_play(frm->tap_m);
        sfMusic_setVolume(frm->tap_m, 300.00);
        frm->menu = 0;
        reset_game(frm, btns, dp);
    }
    if (frm->F8 == 1 && (event.type == sfEvtMouseButtonPressed)) {
        frm->Mouse_mode = 0;
        set_gun_shoot(frm, event, btns);
    }
}

void set_play_action(frm_t *frm, sfEvent event, btn *btns, text *dp)
{
    btns[0].rect.left = 441;
    if (frm->sound_active == 0) {
        sfMusic_play(frm->slide_m);
        sfMusic_setVolume(frm->slide_m, 300.00);
        frm->sound_active = 1;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        sfMusic_stop(frm->tap_m);
        sfMusic_play(frm->tap_m);
        sfMusic_setVolume(frm->tap_m, 300.00);
        frm->menu = 1;
        frm->value_score = 0;
        dp[0].value[0] = '0';
        dp[0].value[1] = '0';
        dp[0].value[2] = '0';
        dp[0].value[3] = '0';
        dp[0].value[4] = '0';
    }
}

void set_quit_action(frm_t *frm, sfEvent event, btn *btns)
{
    btns[4].rect.left = btns[4].rect.width;
    if (frm->sound_active == 0) {
        sfMusic_play(frm->slide_m);
        sfMusic_setVolume(frm->slide_m, 300.00);
        frm->sound_active = 1;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        sfMusic_stop(frm->tap_m);
        sfMusic_play(frm->tap_m);
        sfMusic_setVolume(frm->tap_m, 300.00);
        sfRenderWindow_close(frm->window);
    }
}

void set_button_action(frm_t *frm, sfEvent event, btn *btns, text *dp)
{
    if (frm->active == 1)
        set_quit_action(frm, event, btns);
    else if (frm->active == 2)
        set_play_action(frm, event, btns, dp);
    else if (frm->active == 3) {
        set_back_action(frm, event, btns, dp);
    } else {
        set_gun_shoot(frm, event, btns);
        btns[4].rect.left = 0;
        btns[0].rect.left = 0;
        btns[8].rect.left = 0;
        sfMusic_stop(frm->slide_m);
        frm->sound_active = 0;
    }

}