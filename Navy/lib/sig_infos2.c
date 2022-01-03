/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** sig_infos2
*/

#include "../include/my.h"

void sig_info3(signals_info_t *si, siginfo_t *siginfo,
signals_t *signals, int player)
{
    if (si->e == 3 && si->a != 2)
        si->a = 1;
    if (si->h == 0) {
        interaction_1(player, siginfo, signals);
        si->a = 0;
        si->h = 1;
    } else {
        si->a = 1;
        si->h = 0;
    }
}
