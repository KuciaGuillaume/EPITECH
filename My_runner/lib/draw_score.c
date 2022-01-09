/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** draw_score.c
*/

#include "../include/my.h"

void draw_score_2(window_t *window)
{
    if (window->end_game == 1) {
        sfText_setColor(window->score.score, sfCyan);
        sfText_setPosition(window->score.score, (sfVector2f){910, 335});
        sfText_setPosition(window->score.best_score_text,
        (sfVector2f){910, 540});
        if (window->statics.draw_best_score == 0) {
            sfText_setString(window->score.best_score_text,
            my_itoa(window->score.best_score, 4));
            window->statics.draw_best_score = 1;
        }
        sfRenderWindow_drawText(window->window,
        window->score.best_score_text, NULL);
    }
}

void draw_score(window_t *window)
{
    sfTime time = sfClock_getElapsedTime(window->score.clock);
    float seconds = time.microseconds / 1000000.0;

    if (window->MENU == 1)
        sfRenderWindow_drawText(window->window, window->score.score, NULL);
    if (seconds > 0.5 && window->MENU == 1 && window->button.game_play == 1) {
        window->score.n += 1;
        sfText_setString(window->score.score, my_itoa(window->score.n, 4));
        sfClock_restart(window->score.clock);
    }
    draw_score_2(window);
}
