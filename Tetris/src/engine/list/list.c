/*
** EPITECH PROJECT, 2021
** list
** File description:
** list.c
*/
#include "../../../include/tetris.h"
#include "stdlib.h"

List *list_create_node(void *value)
{
    List *node = malloc(sizeof(List));

    node->value = value;
    node->next = 0;
    return node;
}

void list_insert_first(List **node, void *value)
{
    List *first_node = *node;

    *node = list_create_node(value);
    if (!(*node))
        *node = first_node;
    else
        (*node)->next = first_node;
}

List *list_insert_end(List **node, void *value)
{
    List *list = *node;

    if (!(*node)) {
        *node = list_create_node(value);
        return *node;
    }
    while (list->next)
        list = list->next;
    list->next = list_create_node(value);
    return list->next;
}