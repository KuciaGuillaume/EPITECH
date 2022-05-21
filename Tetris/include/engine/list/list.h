/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef LIST_H
    #define LIST_H

typedef struct s_list List;

struct s_list {

    List *next;
    void *value;

};

List *list_create_node(void *value);

void list_insert_first(List **node, void *value);

List *list_insert_end(List **node, void *value);

void list_delete(List **node);

void list_delete_node(List *node);

void list_delete_first_node(List **list);

void list_delete_last_node(List **list);

int list_size(List *node);

#endif //LIST_H
