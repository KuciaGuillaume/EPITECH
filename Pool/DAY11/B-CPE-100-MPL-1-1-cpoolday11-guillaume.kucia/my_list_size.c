/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday11-guillaume.kucia
** File description:
** my_list_size.c
*/

#include "include/mylist.h"

#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    int size = 0;

    while (begin != NULL) {
        begin = begin->next;
        size += 1;
    }
    return size;
}
