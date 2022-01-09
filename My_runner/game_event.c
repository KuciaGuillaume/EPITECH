/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** game_event.c
*/

#include "include/my.h"

int game_event_3(window_t *window, sfEvent *event, node_t *node)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) &&
    event->mouseButton.button == sfMouseLeft &&
    window->MENU == 1 && window->button.back_to_menu == 1) {
        destroy_reset(node, window, 0);
        return 84;
    }
    if ((sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) &&
    event->mouseButton.button == sfMouseLeft &&
    window->MENU == 1 && window->button.REPLAY == 1) {
        destroy_reset(node, window, 1);
        return 84;
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyP &&
    window->MENU == 1 && window->end_game != 1) {
        if (window->button.game_play == 1)
            window->button.game_play = 0;
        else
            window->button.game_play = 1;
    }
    return game_event_maps(window, event, node);
}

int game_event_2(window_t *window, sfEvent *event, node_t *node)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape) {
        destroy_object(node, window);
        return 84;
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeySpace &&
    window->MENU == 1)
        window->fly = 0;
    if (event->type == sfEvtMouseButtonPressed && event->mouseButton.button
    == sfMouseLeft &&
    window->MENU == 0 && window->button.PLAY == 1) {
        window->MENU = 1;
    }
    if (event->type == sfEvtMouseButtonPressed && event->mouseButton.button
    == sfMouseLeft &&
    window->MENU == 1 && window->button.quit_score == 1) {
        destroy_object(node, window);
        return 84;
    }
    return game_event_3(window, event, node);
}

void game_event_loop(window_t *window, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
    window->MENU == 1 && window->fly != 1 &&
    window->button.game_play == 1) {
        window->save_y = window->perso.offset.y;
        if (window->JUMMODE == 1 && window->double_JUMP == 0)
            window->double_JUMP = 1;
        else
            window->JUMMODE = 1;
        window->fly = 1;
    }
}

int game_event(window_t *window, node_t *node)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            destroy_object(node, window);
            return 84;
        }
        game_event_loop(window, event);
        if (game_event_2(window, &event, node) != 0)
            return 84;
    }
    return 0;
}
