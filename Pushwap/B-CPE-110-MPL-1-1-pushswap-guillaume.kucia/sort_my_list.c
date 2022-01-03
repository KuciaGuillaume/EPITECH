/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** sort_my_list.c
*/

#include "include/my.h"

int check_smaller_in_first(t_node **list)
{
    int n = (*list)->value;
    t_node *copy = (*list);;

    copy = (*list);
    while (copy != NULL) {
        if (copy->value < n)
            return 84;
        copy = copy->next;
    }
    return 0;
}

int check_if_list_is_sort(t_node **list)
{
    int n = (*list)->value;
    t_node *copy = (*list);;

    copy = (*list);
    while (copy != NULL) {
        if (copy->value < n)
            return 84;
        n = copy->value;
        copy = copy->next;
    }
    return 0;
}

int find_the_smallest_path(t_node **list)
{
    t_node *copy = (*list);
    int n = (*list)->value;
    int pos = 0;
    int save_pos = 0;

    copy = (*list);
    while (copy != NULL) {
        if (copy->value < n) {
            n = copy->value;
            save_pos = pos;
        }
        pos += 1;
        copy = copy->next;
    }
    if ((save_pos * 2) >= pos)
        return 1;
    if ((save_pos * 2) <= pos)
        return 0;
    return 0;
}

void list_op(t_node **list, int *i, t_node **listb, int *display)
{
    if ((*list) == NULL)
        return;
    while (check_smaller_in_first(list) == 84) {
        list_op_loop(list, listb, i, display);
    }
    if (check_if_list_is_sort(list) == 0 && (*listb) == NULL) {
        *i = 1;
        return;
    }
}

void sort_my_list(t_node **list, t_node **listb, int *display)
{
    int i = 0;

    while ((*list) != NULL && i == 0) {
        list_op(list, &i, listb, display);
        if (i == 1)
            return;
        pb(list, listb);
        if (display[0] != 2 && display[2] == 1) {
            write(1, "pb", 2);
            display[2] = 0;
        } else if (display[0] != 2)
            write(1, " pb", 3);
        print_my_list(list, listb, display);
    }
    while ((*listb) != NULL && i == 0) {
        sort_my_list_loop(list, listb, display);
    }
}
