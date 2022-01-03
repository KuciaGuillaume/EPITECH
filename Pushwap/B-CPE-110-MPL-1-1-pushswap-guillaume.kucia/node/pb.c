/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** pb.c
*/

#include "../include/my.h"

void add_it_in_listb(t_node **listb, t_node *new_node)
{
    t_node *gap = (*listb);

    if ((*listb) != NULL) {
        gap = (*listb);
        (*listb) = new_node;
        (*listb)->previous = NULL;
        (*listb)->next = gap;
        gap->previous = (*listb);
    } else {
        (*listb) = new_node;
        (*listb)->previous = NULL;
        (*listb)->next = NULL;
    }
}

void pb(t_node **list, t_node **listb)
{
    t_node *new_node = (*list);;

    if ((*list) == NULL)
        return;
    new_node = (*list);
    if ((*list)->next != NULL) {
        (*list) = (*list)->next;
        (*list)->previous = NULL;
    } else
        (*list) = NULL;
    add_it_in_listb(listb, new_node);
}
