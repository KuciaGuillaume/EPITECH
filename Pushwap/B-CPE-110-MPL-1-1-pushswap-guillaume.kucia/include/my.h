/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>

#ifndef __PUSHSWAP__
    #define __PUSHSWAP__

typedef struct s_node t_node;
struct s_node {
    int value;
    t_node *next;
    t_node *previous;
};

void node_push_back(t_node **node, int value, t_node **start);
t_node *node_pop_back(t_node **node);

void node_push_front(t_node **node, int value);
t_node *node_pop_front(t_node **node);

void sa(t_node **l_a);
void sb(t_node **l_b);

void pa(t_node **l_a, t_node **l_b);
void pb(t_node **list, t_node **listb);

void ra(t_node **list);
void rra(t_node **list);

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char *src);
char *my_strcat_char(char *dest, char src);
char *my_strcpy(char *dest, char const *src);
int find_errors(int ac, char **av, int *display);
void class_my_list(t_node **list);
void pa(t_node **listb, t_node **list);
void sort_my_list(t_node **list, t_node **listb, int *display);
void print_my_list(t_node **list, t_node **listb, int *display);
long long int my_put_nbr_long_long(long long int nb);
void sort_my_list_loop(t_node **list, t_node **listb, int *display);
void list_op_loop(t_node **list, t_node **listb, int *i, int *display);
int check_if_list_is_sort(t_node **list);
int find_the_smallest_path(t_node **list);

#endif /* PUSHSWAP */
