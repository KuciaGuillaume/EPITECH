/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** sig_info_interaction.c
*/

#include "../include/my.h"

void sig_info_interaction(int sig, siginfo_t *siginfo)
{
    kill(siginfo->si_pid, SIGUSR2);
}
