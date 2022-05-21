/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** display_score.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void set_score(frm_t *frm, text *dp)
{
    if (frm->value_score > -1)
        dp->value[4] = (frm->value_score % 10) + 48;
    if (frm->value_score >= 10)
        dp->value[3] = ((frm->value_score % 100) / 10) + 48;
    if (frm->value_score >= 100)
        dp->value[2] = ((frm->value_score / 100) % 10) + 48;
    if (frm->value_score >= 1000)
        dp->value[1] = ((frm->value_score / 1000) % 10) + 48;
    if (frm->value_score >= 10000)
        dp->value[0] = (frm->value_score / 10000) + 48;
}
