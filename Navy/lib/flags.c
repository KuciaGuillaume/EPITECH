/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** flags.c
*/

#include "../include/my.h"

void flag_h(void)
{
    my_printf("USAGE\n"
    "     ./navy [first_player_pid] navy_positions\n"
    "DESCRIPTION\n"
    "     first_player_pid: only for the 2nd player."
    " pid of the first player.\n"
    "     navy_positions: file representing the positions"
    " of the ships.\n");
}
