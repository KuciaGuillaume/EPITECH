/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** destroy_text.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void destroy_this_text(node_text_t *start, node_text_t *previous)
{
    if (previous == NULL) {
        engine.game.text = engine.game.text->next;
        engine.game.text->previous = NULL;
        sfText_destroy(start->settings.text);
        return;
    }
    if (start->next == NULL && previous == NULL) {
        engine.game.text = NULL;
        sfText_destroy(start->settings.text);
        return;
    }
    if (start->next == NULL) {
        previous->next = NULL;
        sfText_destroy(start->settings.text);
        return;
    }
    previous->next = start->next;
    start->next->previous = previous;
    sfText_destroy(start->settings.text);
}

void destroy_text_tag(char *tag)
{
    node_text_t *start = engine.game.text;
    node_text_t *previous = NULL;

    for (; start->next; start = start->next) {
        if (equal(start->settings.tag, tag))
            destroy_this_text(start, previous);
        previous = start;
    }
}

void destroy_text(text_t *text)
{
    node_text_t *copy = engine.game.text;
    node_text_t *previous = NULL;

    for (; copy->next; copy = copy->next) {
        if (copy->settings.id == text->id)
            destroy_this_text(copy, previous);
        previous = copy;
    }
}
