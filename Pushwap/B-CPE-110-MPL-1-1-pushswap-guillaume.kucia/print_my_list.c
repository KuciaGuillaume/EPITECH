/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** print_list.c
*/

#include "include/my.h"
#include <stdio.h>

void print_listb(t_node **listb)
{
    my_putstr("(\033[0;34mList B\033[0;00m)");
    if ((*listb) == NULL) {
        my_putstr("{\033[0;33mNULL\033[0;00m}");
        return;
    }
    t_node *copy = (*listb);
    my_putstr("{\033[0;37m");
    while (copy->next != NULL) {
        my_put_nbr_long_long(copy->value);
        my_putstr("\033[0;00m,\033[0;37m");
        copy = copy->next;
    }
    my_put_nbr_long_long(copy->value);
    my_putstr("\033[0;00m}");
}

void print_my_list(t_node **list, t_node **listb, int *display)
{
    display[1] += 1;
    if (display[0] == 0 || display[0] == 2)
        return;
    my_putstr("-> (\033[0;34mList A\033[0;00m)");
    if ((*list) == NULL) {
        my_putstr("{\033[0;33mNULL\033[0;00m} ");
        print_listb(listb);
        my_putstr("\n\n");
        return;
    }
    t_node *copy = (*list);
    my_putstr("{\033[0;37m");
    while (copy->next != NULL) {
        my_put_nbr_long_long(copy->value);
        my_putstr("\033[0;00m,\033[0;37m");
        copy = copy->next;
    }
    my_put_nbr_long_long(copy->value);
    my_putstr("\033[0;00m} ");
    print_listb(listb);
    my_putstr("\n\n");
}
