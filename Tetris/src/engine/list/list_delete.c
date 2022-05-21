/*
** EPITECH PROJECT, 2021
** list
** File description:
** list.c
*/
#include "../../../include/tetris.h"
#include "stdlib.h"

void list_delete(List **node)
{
    List *list = *node;
    List *list_next;

    while (list) {
        list_next = list->next;
        list_delete_node(list);
        list = list_next;
    }
    *node = 0;
}

void list_delete_node(List *node)
{
    free(node);
}

void list_delete_first_node(List **list)
{
    List *curr = *list;

    if (!curr)
        return;
    *list = curr->next;
    free(curr);
}

void list_delete_last_node(List **list)
{
    List *node = *list;
    List *prev = 0;

    if (!node)
        return;
    if (!node->next) {
        *list = 0;
        return;
    }
    while (node->next) {
        prev = node;
        node = node->next;
    }
    free(node);
    prev->next = 0;
}