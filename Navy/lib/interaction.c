/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** interaction
*/

#include "../include/my.h"

void output_ok(char *enter, int player, siginfo_t *siginfo, signals_t *signals)
{
    int i = 0;
    int size = 0;
    int a = -1;

    enter[2] = '\0';
    my_printf("%s: ", enter);
    for (; signals->map[size] != '\n'; size++);
    size += 1;
    for (; signals->map[i] != enter[0]; i++);
    for (; a != enter[1] - 48; a++)
        i += size;
    signals->i = i;
    signals->type = 1;
    set_signals(enter, player, siginfo);
}

void interaction_1(int player, siginfo_t *siginfo, signals_t *signals)
{
    char *enter = malloc(sizeof(char) * 10);

    my_printf("attack: ");
    read(0, enter, 10);
    if (enter[0] < 'A' || enter[0] > 'H') {
        my_printf("wrong position\n");
        interaction_1(player, siginfo, signals);
    } else if (enter[1] < '1' || enter[1] > '8' || enter[2] != '\n') {
        my_printf("wrong position\n");
        interaction_1(player, siginfo, signals);
    } else
        output_ok(enter, player, siginfo, signals);
}
