/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** analyse_event.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void analyse_events(sfRenderWindow *window, frm_t *frm, btn *btns, text *dp)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed)
            set_gun_action(frm, btns);
        if (event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
                sfMusic_play(frm->clover_m);
            if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue)
                sfMusic_pause(frm->clover_m);
            if (sfKeyboard_isKeyPressed(sfKeyB) == sfTrue) {
                if (frm->F8 == 0)
                    frm->F8 = 1;
                else
                    frm->F8 = 0;
            }
        }
        frm->mouse_pos = sfMouse_getPositionRenderWindow(window);
        if (event.type == sfEvtClosed) {
            cleanup_ressources(frm, btns, dp);
            sfRenderWindow_close(window);
        }
        create_button_alive(frm, btns);
        set_button_action(frm, event, btns, dp);
        if (frm->menu == 1) {
            set_gun_move(frm, btns);
        }
    }
}