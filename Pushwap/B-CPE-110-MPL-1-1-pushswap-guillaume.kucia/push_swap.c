/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** pushswap.c
*/

#include "include/my.h"
#include <stdio.h>

void class_my_list(t_node **list)
{
    t_node *new_node = (*list);
    while ((*list)->previous != NULL) {
        new_node = (*list);
        (*list) = (*list)->previous;
        (*list)->next = new_node;
    }
}

void print_total_operations(int *display)
{
    my_putstr("\n--------------\n");
    my_putstr("| \033[0;35mOpérations\033[0;00m | ");
    my_putstr("-> \033[0;37m");
    my_put_nbr_long_long(display[1]);
    my_putstr("\033[0;00m <-\n--------------\n");

}

void print_result(t_node **list, int *display)
{
    if (display[0] == 0)
        return;
    t_node *copy = (*list);
    my_putstr("---------------\n");
    my_putstr("| \033[0;35mSorted list\033[0;00m | ");
    my_putstr("-> \033[0;37m");
    while (copy->next != NULL) {
        my_put_nbr_long_long(copy->value);
        my_putstr("\033[0;00m,\033[0;37m");
        copy = copy->next;
    }
    my_put_nbr_long_long(copy->value);
    my_putstr("\033[0;00m <- \n");
    my_putstr("---------------\n");
    print_total_operations(display);
}

int main(int ac, char **av)
{
    int display[3] = { 0, 0, 1};
    t_node *list = malloc(sizeof(t_node));
    t_node *listb = malloc(sizeof(t_node));
    t_node *start = malloc(sizeof(t_node));

    if (find_errors(ac, av, display) == 84) {
        return 84;
    }
    if (display[0] != 0) {
        my_putchar('\n');
        ac -= 1;
    }
    list = NULL;
    listb = NULL;
    for (int i = 1; i != ac; i += 1)
        node_push_back(&list, my_getnbr(av[i]), &start);
    list = start;
    sort_my_list(&list, &listb, display);
    my_putchar('\n');
    print_result(&list, display);
    return 0;
}
