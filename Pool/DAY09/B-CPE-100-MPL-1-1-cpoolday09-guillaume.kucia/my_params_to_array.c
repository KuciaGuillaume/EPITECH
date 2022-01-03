/*
** EPITECH PROJECT, 2021
** DAY09
** File description:
** my_params_to_array.c
*/

#include <stdlib.h>

#include <stdlib.h>

char **my_str_to_word_array(char const *str);

char *my_strdup(char const *src);

int my_strlen(char const *str);

struct info_param
{
    int length;
    char *str;
    char *copy;
    char **word_array;
};

struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    struct info_param *tableau = malloc(sizeof(struct info_param) * (ac));

    while (i != ac) {
        tableau[i].length = my_strlen(av[i]);
        tableau[i].str = &av[i];
        tableau[i].copy = my_strdup(av[i]);
        tableau[i].word_array = my_str_to_word_array(av[i]);
        i += 1;
    }
    return tableau;
}
