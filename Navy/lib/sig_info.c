/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** sig_info
*/

#include "../include/my.h"

void set_signals_t_1(signals_t *signals, signals_info_t *si)
{
    signals->map;
    signals->empty_map;
    signals->play = 1;
    signals->player = 1;
    signals->type = 1;
    signals->i = 0;
    signals->signal_a = 0;
    signals->signal_i = 0;
    signals->n_boat = 0;
    signals->enemy_alive = 1;
    signals->alive = 1;
    si->a = 2;
    si->e = 0;
    si->h = 1;
    return;
}

void waiting_for_enemy_attack(signals_info_t *si, signals_t *signals)
{
    if (si->a == 1) {
        my_printf("waiting for enemy’s attack...\n");
        signals->type = 2;
        si->e = 0;
        si->a = 0;
    }
}

void sig_info(int sig, siginfo_t *siginfo)
{
    static int i = 0;
    static signals_t signals;
    static signals_info_t si;

    if (i == 0) {
        set_signals_t_1(&signals, &si);
        i = 1;
        my_printf("enemy connected\n\n");
        open_file(name_map, 1, &signals);
        kill(siginfo->si_pid, SIGUSR2);
        interaction_1(2, siginfo, &signals);
        signals.play = 2;
    } else if (sig == 12)
        signals.play = 1;
    if (sig == 10 && si.a != 2)
        si.e += 1;
    if (get_reception(&signals, sig, siginfo) == 1) {
        sig_info3(&si, siginfo, &signals, 2);
        signals.play = 0;
    }
    waiting_for_enemy_attack(&si, &signals);
}

void set_signals_t_2(signals_t *signals, signals_info_t *si)
{
    signals->map;
    signals->empty_map;
    signals->play = 0;
    signals->player = 2;
    signals->type = 2;
    signals->i = 0;
    signals->signal_a = 0;
    signals->signal_i = 0;
    signals->n_boat = 0;
    signals->enemy_alive = 1;
    signals->alive = 1;
    si->a = 2;
    si->e = 0;
    si->h = 0;
    return;
}

void sig_info_2(int sig, siginfo_t *siginfo)
{
    static int i = 0;
    static signals_t signals;
    static signals_info_t si;

    if (i == 0) {
        set_signals_t_2(&signals, &si);
        i = 1;
        my_printf("successfully connected\n\n");
        open_file(name_map, 1, &signals);
        my_printf("waiting for enemy’s attack...\n");
    } else if (sig == 10)
        signals.play = 1;
    if (sig == 12 && si.a != 2)
        si.e += 1;
    if (get_reception(&signals, sig, siginfo) == 1) {
        sig_info3(&si, siginfo, &signals, 1);
        signals.play = 0;
    }
    waiting_for_enemy_attack(&si, &signals);
}
