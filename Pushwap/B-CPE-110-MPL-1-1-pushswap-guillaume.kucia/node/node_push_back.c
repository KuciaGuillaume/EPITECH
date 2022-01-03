/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** node_push_back.c
*/

#include "../include/my.h"

void add_null_node(t_node **node, int value, t_node *new_node)
{
    new_node->previous = NULL;
    new_node->next = NULL;
    new_node->value = value;
    (*node) = new_node;
}

void node_push_back(t_node **node, int value, t_node **start)
{
    t_node *new_node = malloc(sizeof(t_node));

    if (!(*node)) {
        add_null_node(node, value, new_node);
        (*start) = (*node);
        return;
    }
    new_node->previous = (*node);
    (*node)->next = new_node;
    new_node->next = NULL;
    new_node->value = value;
    (*node) = new_node;
}
