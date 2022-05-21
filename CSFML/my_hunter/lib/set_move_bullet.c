/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_move_bullet.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void display_bullet(frm_t *frm, btn *btns)
{
    if (btns[10].move != 0)
        sfRenderWindow_drawSprite(frm->window, btns[10].sprite, NULL);
    if (btns[11].move != 0)
        sfRenderWindow_drawSprite(frm->window, btns[11].sprite, NULL);
    if (btns[12].move != 0)
        sfRenderWindow_drawSprite(frm->window, btns[12].sprite, NULL);
}

void set_bullet_position(btn *btns)
{
    sfVector2f offset;
    if (btns[10].move == 1) {
        offset = sfSprite_getPosition(btns[1].sprite);
        offset.x -= 5;
        sfSprite_setPosition(btns[10].sprite, offset);
        btns[10].move = 2;
    }
    if (btns[11].move == 1) {
        offset = sfSprite_getPosition(btns[1].sprite);
        offset.x -= 5;
        sfSprite_setPosition(btns[11].sprite, offset);
        btns[11].move = 2;
    }
    if (btns[12].move == 1) {
        offset = sfSprite_getPosition(btns[1].sprite);
        offset.x -= 5;
        sfSprite_setPosition(btns[12].sprite, offset);
        btns[12].move = 2;
    }
}

void restart_bullet(btn *btns)
{
    if (btns[10].offset.x != 0 && btns[10].offset.y < 0)
        btns[10].move = 0;
    if (btns[11].offset.x != 0 && btns[11].offset.y < 0)
        btns[11].move = 0;
    if (btns[12].offset.x != 0 && btns[12].offset.y < 0)
        btns[12].move = 0;
}

void set_move_bullet(btn *btns)
{
    sfVector2f offset = {0, -15};
    set_bullet_position(btns);
    if (btns[10].move == 2) {
        sfSprite_move(btns[10].sprite, offset);
        btns[10].offset = sfSprite_getPosition(btns[10].sprite);
    }
    if (btns[11].move == 2) {
        sfSprite_move(btns[11].sprite, offset);
        btns[11].offset = sfSprite_getPosition(btns[11].sprite);
    }
    if (btns[12].move == 2) {
        sfSprite_move(btns[12].sprite, offset);
        btns[12].offset = sfSprite_getPosition(btns[12].sprite);
    }
    restart_bullet(btns);
}