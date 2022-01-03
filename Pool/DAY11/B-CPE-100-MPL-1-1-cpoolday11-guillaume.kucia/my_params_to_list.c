/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday11-guillaume.kucia
** File description:
** my_params_to_list.c
*/

#include <unistd.h>

#include <stdlib.h>

#include <stdio.h>

#include "include/mylist.h"

linked_list_t *create_chest(char * const *av, int i)
{
    linked_list_t *chest = malloc(sizeof(*chest));
    chest->data = av[i];
    chest->next = NULL;
    return chest;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    int i = 0;
    linked_list_t *n;
    linked_list_t *head = NULL;

    while (i != ac) {
        n = create_chest(av, i);
        n->next = head;
        head = n;
        i += 1;
    }
    return head;
}
