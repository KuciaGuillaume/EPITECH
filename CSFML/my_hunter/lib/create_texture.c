/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** create_texte.c
*/

#include "../include/my.h"

void create_texture_and_sprite(btn *btns, int i)
{
    btns[i].texture = sfTexture_createFromFile(btns[i].title, NULL);
    btns[i].sprite = sfSprite_create();
    sfSprite_setTexture(btns[i].sprite, btns[i].texture, sfTrue);
    sfSprite_setPosition(btns[i].sprite, btns[i].offset);
}

void create_police_and_text(text *dp, int i)
{
    dp[i].police = sfFont_createFromFile(dp[i].title);
    dp[i].text = sfText_create();
    sfText_setString(dp[i].text, dp[i].value);
    sfText_setFont(dp[i].text, dp[i].police);
    sfText_setCharacterSize(dp[i].text, dp[i].size);
    sfText_setPosition(dp[i].text, dp[i].offset);
    sfText_setColor(dp[i].text, sfWhite);
}

void create_music(frm_t *frm)
{
    frm->slide_m = sfMusic_createFromFile("lib/lib_sound/slide.wav");
    frm->tap_m = sfMusic_createFromFile("lib/lib_sound/tap.wav");
    frm->no_bullet_m = sfMusic_createFromFile("lib/lib_sound/no_bullet.wav");
    frm->reload_shotgun_m =
    sfMusic_createFromFile("lib/lib_sound/reload_shotgun.wav");
    frm->gun_m = sfMusic_createFromFile("lib/lib_sound/shotgun_shooting.wav");
    frm->clover_m = sfMusic_createFromFile("lib/lib_sound/clover.ogg");
    sfMusic_setLoop(frm->clover_m, sfTrue);
    sfMusic_setVolume(frm->clover_m, 30.00);
    sfMusic_play(frm->clover_m);
}
