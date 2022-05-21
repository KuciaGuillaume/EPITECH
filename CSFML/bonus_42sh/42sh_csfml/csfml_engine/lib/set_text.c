/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text.c
*/

#include "my.h"
#include "engine.h"

void set_text_tag(char *tag, char *text)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next)
        if (equal(start->settings.tag, tag) == true)
            sfText_setString(start->settings.text, text);
}

void set_text_text(text_t *text, char *str)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next) {
        if (start->settings.id == text->id) {
            sfText_setString(start->settings.text, str);
            text->text = start->settings.text;
        }
    }
}
