/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** add_node.c
*/

#include "../include/my.h"

void add_null_node(node_t **node, obj_t *object, node_t *new_node)
{
    new_node->previous = NULL;
    new_node->next = NULL;
    new_node->value = object;
    (*node) = new_node;
}

void add_node(node_t **node, obj_t *object)
{
    node_t *new_node = malloc(sizeof(node_t));
    if ((*node) == NULL) {
        add_null_node(node, object, new_node);
        return;
    }
    new_node->previous = (*node);
    (*node)->next = new_node;
    new_node->next = NULL;
    new_node->value = object;
    (*node) = new_node;
}
