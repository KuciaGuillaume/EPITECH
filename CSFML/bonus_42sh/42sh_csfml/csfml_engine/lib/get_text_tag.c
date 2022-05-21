/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** get_text_tag.c
*/

#include "engine.h"

sfText *get_text_tag(char *tag)
{
    node_text_t *list = engine.game.text;

    for (; list != NULL; list = list->next)
        if (equal(list->settings.tag, tag))
            return list->settings.text;
    return NULL;
}
