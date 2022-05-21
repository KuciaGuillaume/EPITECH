/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** create_button_alive.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void create_button_alive(frm_t *frm, btn *btns)
{
    if ((frm->mouse_pos.x >= btns[4].offset.x) &&
    frm->mouse_pos.x <= (btns[4].offset.x +
    btns[4].rect.width) && (frm->mouse_pos.y >=
    btns[4].offset.y) && (frm->mouse_pos.y <=
    btns[4].offset.y + btns[4].rect.height) && frm->menu == 0)
        frm->active = 1;
    else if ((frm->mouse_pos.x >= btns[0].offset.x) &&
    frm->mouse_pos.x <= (btns[0].offset.x +
    btns[0].rect.width) && (frm->mouse_pos.y >=
    btns[0].offset.y) && (frm->mouse_pos.y <=
    btns[0].offset.y + btns[0].rect.height) && frm->menu == 0)
        frm->active = 2;
    else if ((frm->mouse_pos.x >= btns[8].offset.x) &&
    frm->mouse_pos.x <= (btns[8].offset.x +
    btns[8].rect.width) && (frm->mouse_pos.y >=
    btns[8].offset.y) && frm->mouse_pos.y <= btns[8].offset.y +
    btns[8].rect.height) {
        if (frm->F8 != 1)
            frm->active = 3;
    }
    else
        frm->active = 0;

}
