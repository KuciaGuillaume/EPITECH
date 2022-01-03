/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** ra.c
*/

#include "../include/my.h"
#include "stdio.h"

void ra(t_node **list)
{
    t_node *new_node = (*list);
    t_node *prev = (*list);

    if ((*list) == NULL)
        return;
    new_node = (*list);
    (*list) = (*list)->next;
    (*list)->previous = NULL;
    while ((*list)->next != NULL) {
        prev = (*list);
        (*list) = (*list)->next;
        (*list)->previous = prev;
    }
    new_node->previous = (*list);
    (*list)->next = new_node;
    new_node->next = NULL;
    class_my_list(list);
}
