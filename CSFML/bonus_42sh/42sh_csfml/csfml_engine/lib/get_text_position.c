/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_text_position.c
*/

#include "my.h"
#include "engine.h"

sfVector2f get_text_position_tag(char *tag)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next)
        if (equal(start->settings.tag, tag) == true)
            return sfText_getPosition(start->settings.text);
    return (sfVector2f){0, 0};
}

sfVector2f get_text_position_text(text_t text)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next)
        if (start->settings.id == text.id)
            return sfText_getPosition(start->settings.text);
    return (sfVector2f){0, 0};
}
