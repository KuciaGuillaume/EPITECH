/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** reception_des_signaux.c
*/

#include "../include/my.h"

void set_signals(char *enter, int player, siginfo_t *siginfo)
{
    static int b = 0;
    if (player == 1)
        kill(siginfo->si_pid, SIGUSR1);
    else
        kill(siginfo->si_pid, SIGUSR2);
    for (int i = 0; enter[i] != '\0'; i++) {
        usleep(10000);
        for (int a = 0; a != enter[i]; a++) {
            set_signals2(player, siginfo);
            usleep(10000);
            b += 1;
        }
        b = 0;
        usleep(10000);
        if (player == 1)
            kill(siginfo->si_pid, SIGUSR1);
        else
            kill(siginfo->si_pid, SIGUSR2);
    }
}

void back_get_info_attack(char *attack, siginfo_t *siginfo,
int player, signals_t *signals)
{
    if (my_strcmp(attack, "missed") == 0) {
        if (player == 1)
            set_signals("11\0", 2, siginfo);
        if (player == 2)
            set_signals("11\0", 1, siginfo);
    }
    if (my_strcmp(attack, "hit") == 0) {
        if (player == 1)
            set_signals("22\0", 2, siginfo);
        if (player == 2)
            set_signals("22\0", 1, siginfo);
    }
    if (my_strcmp(attack, "dead") == 0) {
        if (player == 1)
            set_signals("33\0", 2, siginfo);
        if (player == 2)
            set_signals("33\0", 1, siginfo);
        signals->alive = 0;
    }
}

void get_info_attack(char *coordinated, siginfo_t *siginfo, signals_t *signals)
{
    int i = 0;
    int size = 0;
    int a = -1;

    if (get_info_attack_reception(coordinated, signals) == 1)
        return;
    for (; signals->map[size] != '\n'; size++);
    size += 1;
    for (; signals->map[i] != coordinated[0]; i++);
    for (; a != coordinated[1] - 48; a++)
        i += size;
    get_info_attack_back(signals, i, siginfo);
}

int get_reception_2(char *coordinated, siginfo_t *siginfo, signals_t *signals)
{
    if (signals->signal_a != 2)
        return 0;
    else {
        signals->signal_a = 0;
        signals->signal_i = 0;
        get_info_attack(coordinated, siginfo, signals);
        return 1;
    }
    return 0;
}

int get_reception(signals_t *signals, int sig, siginfo_t *siginfo)
{
    static int s1 = 0;
    static int s2 = 0;
    static char coordinated[3];

    if (signals->play != 1 || signals->play == 2)
        return 0;
    set_s1_and_s2(signals, &s1, &s2);
    if (sig == s1)
        signals->signal_i += 1;
    if (sig == s2) {
        if (signals->signal_a == 0)
            coordinated[0] = signals->signal_i;
        if (signals->signal_a == 1)
            coordinated[1] = signals->signal_i;
        signals->signal_a += 1;
        signals->signal_i = 0;
    }
    return get_reception_2(coordinated, siginfo, signals);
}
