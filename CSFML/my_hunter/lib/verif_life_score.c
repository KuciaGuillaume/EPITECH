/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** verif_life_score.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void verif_life_score(frm_t *frm, btn *btns)
{
    static int n = 100;
    if (frm->value_score >= n) {
        if (btns[16].rect.left <= btns[16].size_width - 468)
            btns[16].rect.left -= 468;
        else if (btns[16].rect.left <= 234)
            btns[16].rect.left -= 234;
        btns[14].status = 1;
        frm->timer = 0.50;
        n += 100;
    }
}