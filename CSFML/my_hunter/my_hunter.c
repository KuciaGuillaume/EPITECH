/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** my_hunter.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

void cleanup_ressources(frm_t *frm, btn *btns, text *dp)
{
    int i = 0;

    while (i != 17) {
        sfSprite_destroy(btns[i].sprite);
        sfTexture_destroy(btns[i].texture);
        i += 1;
    }
    sfText_destroy(dp[0].text);
    sfText_destroy(dp[1].text);
    sfMusic_destroy(frm->gun_m);
    sfMusic_destroy(frm->slide_m);
    sfMusic_destroy(frm->tap_m);
    sfMusic_destroy(frm->clover_m);
    sfRenderWindow_destroy(frm->window);
}

void game_event(frm_t *frm, int i, btn *btns, text *dp)
{
    if (i == 0) {
        set_game_event_1(frm, btns, dp);
    }
    if (i == 1) {
        set_game_event_2(frm, btns, dp);
    }
}

void game_loop(frm_t *frm, btn *btns, text *dp)
{
    game_event(frm, 0, btns, dp);
    game_event(frm, 1, btns, dp);
    if (sfRenderWindow_isOpen(frm->window))
        game_loop(frm, btns, dp);
}

int create_settings_window(frm_t *frm, btn *btns, text *dp)
{
    int e = 0;
    int i = initialise_value(frm, btns);
    while (e != 2) {
        create_police_and_text(dp, e);
        e += 1;
    }
    create_music(frm);
    sfRenderWindow_setFramerateLimit(frm->window, 60);
    frm->clock = sfClock_create();
    frm->clock_reload = sfClock_create();
    frm->clock_energy = sfClock_create();
    sfRenderWindow_setMouseCursorVisible(frm->window, sfFalse);
    return i;
}

int main(int ac, char **av)
{
    frm_t frm;
    int i;
    btn *btns = set_my_btns();
    text *dp = set_my_dp();
    frm.F8 = 0;

    if (ac != 1) {
        display_my_description(av);
        return EXIT_SUCCESS;
    }
    i = create_settings_window(&frm, btns, dp);
    if (i != 84)
        game_loop(&frm, btns, dp);
    cleanup_ressources(&frm, btns, dp);
    if (i == 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}
