/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** draw_x.c
*/

#include "../include/my.h"

void won_and_dead(signals_t *signals)
{
    if (signals->alive == 0) {
        usleep(100000);
        my_printf("Enemy won\n\n");
        exit(0);
    }
    if (signals->enemy_alive == 0) {
        usleep(100000);
        my_printf("I won\n\n");
        exit(0);
    }
}

void draw_x_2(signals_t *signals, int i, char *boat)
{
    if (signals->type == 1 && signals->player == 2) {
        if (my_strcmp(boat, "missed") == 0)
            signals->empty_map[i] = 'o';
        else
            signals->empty_map[i] = 'x';
        my_printf("\nmy positions:\n%s\n\n", signals->map);
        my_printf("enemy's positions:\n%s\n\n", signals->empty_map);
        won_and_dead(signals);
    }
    if (signals->player == 1 && signals->type == 1) {
        if (my_strcmp(boat, "missed") == 0)
            signals->empty_map[i] = 'o';
        else
            signals->empty_map[i] = 'x';
        my_printf("\n");
    }
}

void draw_x(signals_t *signals, int i, char *boat)
{
    if (signals->type == 2 && signals->player == 1) {
        if (my_strcmp(boat, "missed") == 0)
            signals->map[i] = 'o';
        else
            signals->map[i] = 'x';
        my_printf("\nmy positions:\n%s\n\n", signals->map);
        my_printf("enemy's positions:\n%s\n\n", signals->empty_map);
        won_and_dead(signals);
    }
    if (signals->player == 2 && signals->type == 2) {
        if (my_strcmp(boat, "missed") == 0)
            signals->map[i] = 'o';
        else
            signals->map[i] = 'x';
        my_printf("\n");
    }
    draw_x_2(signals, i, boat);
}
