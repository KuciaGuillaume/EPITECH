/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** rra.c
*/

#include "../include/my.h"
#include <stdio.h>

void rra(t_node **list)
{
    t_node *new;
    t_node *prev;

    if ((*list) == NULL)
        return;
    new = (*list);
    while (new->next != NULL) {
        prev = new;
        new = new->next;
        new->previous = prev;
    }
    new->previous->next = NULL;
    new->previous = NULL;
    new->next = (*list);
    (*list)->previous = new;
    class_my_list(list);
}
