/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** pb.c
*/

#include "../include/my.h"

void add_it_in_list(t_node **list, t_node *new_node)
{
    if ((*list) != NULL) {
        (*list)->previous = new_node;
        new_node->previous = NULL;
        new_node->next = (*list);
        (*list) = (*list)->previous;
    } else {
        (*list) = new_node;
        (*list)->previous = NULL;
        (*list)->next = NULL;
    }
}

void pa(t_node **listb, t_node **list)
{
    t_node *new_node = (*list);;

    if ((*listb) == NULL)
        return;
    new_node = (*listb);
    if ((*listb)->next != NULL) {
        (*listb) = (*listb)->next;
        (*listb)->previous = NULL;
    } else
        (*listb) = NULL;
    add_it_in_list(list, new_node);
}
