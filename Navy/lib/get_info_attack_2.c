/*
** EPITECH PROJECT, 2022
** ù
** File description:
** get_info_attack_2
*/

#include "../include/my.h"

int get_info_attack_reception(char *coordinated, signals_t *signals)
{
    if (my_strcmp(coordinated, "22") == 0) {
        my_printf("hit\n");
        usleep(100000);
        draw_x(signals, signals->i, "hit");
        return 1;
    }
    if (my_strcmp(coordinated, "11") == 0) {
        my_printf("missed\n");
        usleep(100000);
        draw_x(signals, signals->i, "missed");
        return 1;
    }
    if (my_strcmp(coordinated, "33") == 0) {
        my_printf("hit\n");
        usleep(100000);
        signals->enemy_alive = 0;
        draw_x(signals, signals->i, "hit");
        return 1;
    } else
        my_printf("%s: ", coordinated);
    return 0;
}

void get_info_attack_back(signals_t *signals, int i, siginfo_t *siginfo)
{
    if (signals->map[i] != '.' && signals->map[i] != 'x') {
        signals->n_boat -= 1;
        my_printf("hit\n");
        if (signals->n_boat != 0)
            back_get_info_attack("hit", siginfo, signals->player, signals);
        else
            back_get_info_attack("dead", siginfo, signals->player, signals);
        usleep(100000);
        draw_x(signals, i, "hit");
    } else {
        my_printf("missed\n");
        back_get_info_attack("missed", siginfo, signals->player, signals);
        usleep(100000);
        draw_x(signals, i, "missed");
    }
}
