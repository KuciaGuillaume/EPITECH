/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text_size.c
*/

#include "my.h"
#include "engine.h"

void set_text_size_tag(char *tag, int size)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next) {
        if (equal(start->settings.tag, tag) == true) {
            sfText_setCharacterSize(start->settings.text, size);
            start->settings.font_size = size;
        }
    }
}

void set_text_size_text(text_t *text, int size)
{
    node_text_t *start = engine.game.text;

    text->font_size = size;
    for (; start; start = start->next) {
        if (start->settings.id == text->id) {
            sfText_setCharacterSize(start->settings.text, size);
            start->settings.font_size = size;
        }
    }
}
