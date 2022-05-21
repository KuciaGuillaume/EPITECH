/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text_visible.c
*/

#include "my.h"
#include "engine.h"

void set_text_visible_tag(char *tag, bool visible)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next)
        if (equal(start->settings.tag, tag) == true)
            start->settings.display = visible;

}

void set_text_visible_text(text_t *text, bool visible)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next)
        if (start->settings.id == text->id)
            start->settings.display = visible;
}
