/*
** EPITECH PROJECT, 2021
** solver
** File description:
** add_node.c
*/

#include "my.h"

void new_node(opt_t *opt, int val, i2f pos)
{
    list_t *new_node = malloc(sizeof(list_t));
    open_node_t open_val;

    open_val.val = val;
    open_val.pos = pos;
    if (opt->list != NULL) {
        new_node->previous = opt->list;
        opt->list->next = new_node;
        new_node->next = NULL;
        new_node->node = open_val;
        opt->list = new_node;
    } else {
        new_node->previous = NULL;
        new_node->next = NULL;
        new_node->node = open_val;
        opt->list = new_node;
    }
}
