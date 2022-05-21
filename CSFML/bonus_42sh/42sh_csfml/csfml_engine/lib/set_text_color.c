/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text_color.c
*/

#include "my.h"
#include "engine.h"

void set_text_color_tag(char *tag, sfColor color)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next) {
        if (equal(start->settings.tag, tag) == true) {
            start->settings.color = color;
            sfText_setColor(start->settings.text, color);
        }
    }
}

void set_text_color_text(text_t *text, sfColor color)
{
    node_text_t *start = engine.game.text;

    text->color = color;
    for (; start; start = start->next) {
        if (start->settings.id == text->id) {
            start->settings.color = color;
            sfText_setColor(start->settings.text, color);
        }
    }
}
