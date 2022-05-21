/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_game_menu.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void set_game_menu_draw_srpite(frm_t *frm, btn *btns)
{
    sfRenderWindow_drawSprite(frm->window, btns[7].sprite, NULL);
    sfRenderWindow_drawSprite(frm->window, btns[1].sprite, NULL);
    sfRenderWindow_drawSprite(frm->window, btns[5].sprite, NULL);
    sfRenderWindow_drawSprite(frm->window, btns[6].sprite, NULL);
    sfRenderWindow_drawSprite(frm->window, btns[8].sprite, NULL);
    sfRenderWindow_drawSprite(frm->window, btns[16].sprite, NULL);
}

void set_game_menu_1(frm_t *frm, btn *btns, text *dp)
{
    set_game_menu_draw_srpite(frm, btns);
    if (btns[9].status != 0)
        sfRenderWindow_drawSprite(frm->window, btns[9].sprite, NULL);
    if (btns[13].status != 0 && btns[13].status != (-2))
        sfRenderWindow_drawSprite(frm->window, btns[13].sprite, NULL);
    if (btns[14].status != 0 && btns[14].status != (-2))
        sfRenderWindow_drawSprite(frm->window, btns[14].sprite, NULL);
    if (frm->Mouse_mode == 0) {
        sfRenderWindow_drawSprite(frm->window, btns[2].sprite, NULL);
    } else if (frm->Mouse_mode == 1) {
        sfRenderWindow_drawSprite(frm->window, btns[15].sprite, NULL);
    }
    dp[0].offset = (sfVector2f){900, 980};
    sfText_setCharacterSize(dp[0].text, 30);
    sfText_setPosition(dp[0].text, dp[0].offset);
    sfText_setString(dp[0].text, dp[0].value);
    sfRenderWindow_drawText(frm->window, dp[0].text, NULL);
    sfText_setString(dp[1].text, dp[1].value);
    if (frm->calc_time_left > 0)
        sfRenderWindow_drawText(frm->window, dp[1].text, NULL);
    display_bullet(frm, btns);
    reload_shotgun(frm, btns, dp);
    set_move_bullet(btns);
    set_score(frm, dp);

}

void set_game_menu(frm_t *frm, int menu, btn *btns, text *dp)
{
    if (menu == 1)
        set_game_menu_1(frm, btns, dp);
    else {
        sfRenderWindow_drawSprite(frm->window, btns[3].sprite, NULL);
        sfRenderWindow_drawSprite(frm->window, btns[4].sprite, NULL);
        sfRenderWindow_drawSprite(frm->window, btns[0].sprite, NULL);
        sfRenderWindow_drawSprite(frm->window, btns[15].sprite, NULL);
        sfText_setString(dp[0].text, dp[0].value);
        dp[0].offset = (sfVector2f){950, 112};
        sfText_setPosition(dp[0].text, dp[0].offset);
        sfText_setCharacterSize(dp[0].text, 15);
        sfRenderWindow_drawText(frm->window, dp[0].text, NULL);
    }
}
