/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** initiate_window.c
*/

#include "../include/my.h"
#include <stdlib.h>

void initiate_statics(window_t *window)
{
    window->statics.get_collisions = 0;
    window->statics.get_rect = 0;
    window->statics.get_rect_type_10 = 0;
    window->statics.get_rect_menu = 0;
    window->statics.get_rect_top = 0;
    window->statics.jump_a = 0;
    window->statics.jump_drop = 0.09;
    window->statics.jump_up = 12;
    window->statics.jump_e = 0;
    window->statics.nothing = 0;
    window->statics.get_collisions_nothing = 0;
    window->statics.draw_best_score = 0;
}

void initiate_window_first(window_t *window)
{
    window->JUMMODE = 0;
    window->score.best_score = 0;
    window->double_JUMP = 0;
    window->MENU = 0;
    window->button.PLAY = 0;
    window->button.quit_score = 0;
    window->button.back_to_menu = 0;
    window->button.REPLAY = 0;
    window->life = 3;
    window->fly = 0;
    window->end_game = 0;
    window->spawn_reset = -600;
    window->button.game_play = 1;
    window->speed = -1.3;
    window->multiply = 1.001;
    window->multiply *= (window->difficulty / 1000) + 1;
    window->clock = sfClock_create();
}

void initiate_score(window_t *window)
{
    window->score.n = 0;
    window->score.text = my_itoa(window->score.n, 0);
    window->score.clock = sfClock_create();
    window->score.police = sfFont_createFromFile("lib/lib_police/"
    "Hugie Bunny.ttf");
    window->score.score = sfText_create();
    sfText_setString(window->score.score, window->score.text);
    sfText_setFont(window->score.score, window->score.police);
    sfText_setCharacterSize(window->score.score, 50);
    sfText_setPosition(window->score.score, (sfVector2f){1755, 65});
    sfText_setColor(window->score.score, sfWhite);
    window->score.best_score_text = sfText_create();
    sfText_setFont(window->score.best_score_text, window->score.police);
    sfText_setCharacterSize(window->score.best_score_text, 50);
    sfText_setColor(window->score.best_score_text, sfWhite);

}

void initiate_window(window_t *window)
{
    static int i = 0;

    initiate_window_first(window);
    initiate_statics(window);
    initiate_score(window);
    window->perso.info_pos = (sfVector2f){0, 0};
    window->button.home_map = 0;
    window->save_y = 0;
    if (i == 0) {
        window->sound.background = sfMusic_createFromFile("lib/lib_sound/"
        "background_music.wav");
        sfMusic_play(window->sound.background);
        sfMusic_setLoop(window->sound.background, sfTrue);
        i = 1;
    }
}
