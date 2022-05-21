/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_my_btns.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

text *set_my_dp(void)
{
    text *dp = malloc(sizeof(btn) * 3);

    dp[0] = (text){"lib/lib_police/Hugie Bunny.ttf", (sfVector2f){900, 980},
        {'0', '0', '0', '0', '\0'}, 30, (sfFont*){NULL}, (sfText*){NULL}};
    dp[1] = (text){"lib/lib_police/Hugie Bunny.ttf", (sfVector2f){300, 980}, {'2',
        '.', '0', 's', '\0'}, 30, (sfFont*){NULL}, (sfText*){NULL}};
    return dp;
}

btn *set_my_btns_3(btn *btns)
{
    btns[11] = (btn){"lib/lib_image/one_bullet.png",
    20, 19, (sfIntRect){0, 0, 0, 0}, (sfVector2f){ 0, 0},
    0, 1, (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[12] = (btn){"lib/lib_image/one_bullet.png", 20,
    19, (sfIntRect){0, 0, 0, 0}, (sfVector2f){ 0, 0}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[13] = (btn){"lib/lib_image/Energy.png", 1900, 95,
    (sfIntRect){0, 0, 95, 95}, (sfVector2f){1800, 200}, -7,
    (-2), (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[14] = (btn){"lib/lib_image/Energy.png", 1900, 95,
    (sfIntRect){0, 0, 95, 95}, (sfVector2f){1800, 200}, -3,
    (-2), (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[15] = (btn){"lib/lib_image/curseur.png", 33, 33,
    (sfIntRect){0, 0, 0, 0}, (sfVector2f){300, 300}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[16] = (btn){"lib/lib_image/life.png", 1638, 76,
    (sfIntRect){0, 0, 234, 76}, (sfVector2f){1630, 965}, 0,
    1, (sfTexture*){NULL}, (sfSprite*){NULL}};
    return btns;
}

btn *set_my_btns_2(btn *btns)
{
    btns[6] = (btn){"lib/lib_image/bullet.png", 888, 72,
    (sfIntRect){0, 0, 222, 72}, (sfVector2f){50, 968}, 0,
    1, (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[7] = (btn){"lib/lib_image/BackgroundMouvant.png", 5760,
    1080, (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0}, 0,
    1, (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[8] = (btn){"lib/lib_image/RETOUR.png", 292, 50,
    (sfIntRect){0, 0, 146, 50}, (sfVector2f){20, 20}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[9] = (btn){"lib/lib_image/Energy.png", 1900, 95,
    (sfIntRect){0, 0, 95, 95}, (sfVector2f){1800, 200}, -5, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[10] = (btn){"lib/lib_image/one_bullet.png", 20, 19,
    (sfIntRect){0, 0, 0, 0}, (sfVector2f){ 0, 0}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    return set_my_btns_3(btns);
}

btn *set_my_btns(void)
{
    btn *btns = malloc(sizeof(btn) * 18);

    btns[0] = (btn){"lib/lib_image/JOUER.png", 882, 118,
    (sfIntRect){0, 0, 441, 118}, (sfVector2f){0, 0}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[1] = (btn){"lib/lib_image/gun.png", 33, 182,
    (sfIntRect){0, 0, 0, 0}, (sfVector2f){0, 0}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[2] = (btn){"lib/lib_image/cible.png", 32, 33,
    (sfIntRect){0, 0, 0, 0}, (sfVector2f){300, 300}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[3] = (btn){"lib/lib_image/Background.png", 1920, 1080,
    (sfIntRect){0, 0, 0, 0}, (sfVector2f){0, 0}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[4] = (btn){"lib/lib_image/Quit_game.png", 882, 115,
    (sfIntRect){0, 0, 441, 118}, (sfVector2f){0, 962}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    btns[5] = (btn){"lib/lib_image/taskath.png", 1878, 115,
    (sfIntRect){0, 0, 0, 0}, (sfVector2f){20, 945}, 0, 1,
    (sfTexture*){NULL}, (sfSprite*){NULL}};
    return set_my_btns_2(btns);
}