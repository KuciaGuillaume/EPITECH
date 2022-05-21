/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** display_text.c
*/

#include "my.h"
#include "engine.h"

void display_text(void)
{
    node_text_t *start = engine.game.text;

    for (; start; start = start->next)
        if (start->settings.display == true && start->settings.exist == true)
            sfRenderWindow_drawText(engine.win_settings.window,
            start->settings.text, NULL);
}
