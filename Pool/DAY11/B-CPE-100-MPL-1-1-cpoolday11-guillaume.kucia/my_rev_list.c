/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday11-guillaume.kucia
** File description:
** my_rev_list.c
*/

#include <stdlib.h>

#include <stdio.h>

#include "include/mylist.h"

void created_loop(linked_list_t **actual, linked_list_t **suivant,
linked_list_t **precedent)
{
    *suivant = (*actual)->next;
    (*actual)->next = *precedent;
    *precedent = *actual;
    *actual = *suivant;
}

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *suivant = 0;
    linked_list_t *actual = *begin;
    linked_list_t *precedent = 0;

    while (actual){
        created_loop(&actual, &suivant, &precedent);
    }
    (*begin) = precedent;
}
