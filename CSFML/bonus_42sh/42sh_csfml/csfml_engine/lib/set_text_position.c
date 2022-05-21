/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text_position.c
*/

#include "my.h"
#include "engine.h"

void set_text_position_tag(char *tag, V2f position)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next)
        if (equal(start->settings.tag, tag) == true)
            sfText_setPosition(start->settings.text, position);
}

void set_text_position_text(text_t text, V2f position)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next)
        if (start->settings.id == text.id)
            sfText_setPosition(start->settings.text, position);
}
