/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** initialise_value.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include <SFML/Audio.h>

int initialise_value(frm_t *frm, btn *btns)
{
    int e = 0;
    sfVideoMode mode = {1920, 1080, 64};
    frm->menu = 0;
    frm->sound_active = 0;
    frm->Mouse_mode = 0;
    frm->timer = 1.00;
    frm->calc_time_left = 1.00;
    frm->speed_vector = 1;
    frm->value_score = 0;
    frm->energy_up = (-1);
    frm->window = sfRenderWindow_create(mode, "SFML window",
    sfFullscreen | sfResize | sfClose , NULL);
    if (!frm->window)
        return 84;
    while (e != 17) {
        create_texture_and_sprite(btns, e);
        e += 1;
    }
    return 0;
}
