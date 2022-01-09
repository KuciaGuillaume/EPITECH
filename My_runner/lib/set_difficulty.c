/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** set_difficulty.c
*/

#include "../include/my.h"

void set_difficulty(window_t *window)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 1 && window->MENU == 1) {
        if ((window->speed * window->multiply) > -3.4)
            window->speed *= window->multiply;
        sfClock_restart(window->clock);
    }
}
