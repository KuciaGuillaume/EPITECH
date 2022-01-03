/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** sort_my_list_loop.c
*/

#include "include/my.h"

void sort_my_list_loop(t_node **list, t_node **listb, int *display)
{
    pa(listb, list);
    if (display[0] != 2 && display[2] == 1) {
        write(1, "pa", 2);
        display[2] = 0;
    } else if (display[0] != 2)
        write(1, " pa", 3);
    print_my_list(list, listb, display);
}

void list_op_loop(t_node **list, t_node **listb, int *i, int *display)
{
    if (check_if_list_is_sort(list) == 0 && (*listb) == 0) {
        *i = 1;
        return;
    }
    if (find_the_smallest_path(list) == 1) {
        rra(list);
        if (display[0] != 2 && display[2] == 1) {
            write(1, "rra", 3);
            display[2] = 0;
        } else if (display[0] != 2)
            write(1, " rra", 4);
        print_my_list(list, listb, display);
    } else {
        ra(list);
        if (display[0] != 2 && display[2] == 1) {
            write(1, "ra", 2);
            display[2] = 0;
        } else if (display[0] != 2)
            write(1, " ra", 3);
        print_my_list(list, listb, display);
    }
}
