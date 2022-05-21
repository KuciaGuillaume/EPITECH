/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** move.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void calc_time_left(frm_t *frm, text *dp)
{
    int value;
    float intermediate;
    frm->calc_time_left = (frm->timer - frm->seconds_reload);
    dp[1].value[0] = ((int)frm->calc_time_left) + 48;
    intermediate = frm->calc_time_left * 10;
    value = (int)intermediate % 10;
    dp[1].value[1] = '.';
    dp[1].value[2] = value + 48;
    dp[1].value[3] = 's';
    dp[1].value[4] = '\0';
}

void reload_shotgun(frm_t *frm, btn *btns, text *dp)
{
    if (frm->seconds_reload > frm->timer && btns[6].rect.left != 0) {
        btns[6].rect.left -= btns[6].rect.width;
        dp[1].value[0] = '0';
        dp[1].value[1] = '.';
        dp[1].value[2] = '0';
        dp[1].value[3] = 's';
        dp[1].value[4] = '\0';
        sfMusic_stop(frm->reload_shotgun_m);
        sfMusic_play(frm->reload_shotgun_m);
        sfClock_restart(frm->clock_reload);
    } else {
        calc_time_left(frm, dp);
    }
}
