/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** signals2
*/

#include "../include/my.h"

void set_signals2(int player, siginfo_t *siginfo)
{
    if (player == 1)
        kill(siginfo->si_pid, SIGUSR2);
    else
        kill(siginfo->si_pid, SIGUSR1);
}
