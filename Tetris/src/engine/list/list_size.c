/*
** EPITECH PROJECT, 2021
** list
** File description:
** list.c
*/
#include "../../../include/tetris.h"

int list_size(List *node)
{
    int i = 1;

    if (!node)
        return 0;
    while (node->next) {
        i++;
        node = node->next;
    }
    return i;
}