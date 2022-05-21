/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_game_event_1.c
*/

#include "../include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>

void reset_game(frm_t *frm, btn *btns, text *dp)
{
    frm->menu = 0;
    frm->sound_active = 0;
    frm->Mouse_mode = 0;
    frm->timer = 1.00;
    frm->calc_time_left = 1.00;
    frm->speed_vector = 1;
    frm->energy_up = (-1);
    btns[16].rect.left = 0;
    restart_energy(frm, btns);
    restart_energy_2(frm, btns);
    restart_energy_3(frm, btns);
    btns[9].status = (-2);
    btns[13].status = (-2);
    btns[14].status = (-2);
    set_score(frm, dp);
}

void set_game_event_2(frm_t *frm, btn *btns, text *dp)
{
    sfRenderWindow_clear(frm->window, sfBlack);
    btns[15].offset.x = frm->mouse_pos.x - 8;
    btns[15].offset.y = frm->mouse_pos.y;
    sfSprite_setPosition(btns[15].sprite, btns[15].offset);
    set_game_menu(frm, frm->menu, btns, dp);
    sfRenderWindow_display(frm->window);
    if (btns[9].status != 0)
        find_collisions(frm, btns);
    if (btns[13].status != 0 && btns[13].status != (-2))
        find_collisions_energy2(frm, btns);
    if (btns[14].status != 0 && btns[14].status != (-2))
        find_collisions_energy3(frm, btns);
    if (btns[16].rect.left >= btns[16].size_width - btns[16].rect.width) {
        reset_game(frm, btns, dp);
    }
    verif_life_score(frm, btns);
}

void set_game_event_1(frm_t *frm, btn *btns, text *dp)
{
    analyse_events(frm->window, frm, btns, dp);
    set_opt_button(frm, btns);
    frm->time = sfClock_getElapsedTime(frm->clock);
    frm->seconds = frm->time.microseconds / 1000000.0;
    frm->time_energy = sfClock_getElapsedTime(frm->clock_energy);
    frm->seconds_energy = frm->time_energy.microseconds / 1000000.0;
    active_energy_animation(frm, btns);
    if (btns[6].rect.left != 0) {
        frm->time_reload = sfClock_getElapsedTime(frm->clock_reload);
        frm->seconds_reload = frm->time_reload.microseconds / 1000000.0;
    } else {
        sfClock_restart(frm->clock_reload);
    }
}