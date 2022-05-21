/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/
#include "../../../include/tetris.h"

int my_strcmp(char *s1 , char *s2)
{
    int i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] > s2[i])
            return s1[i] - s2[i];
        if (s1[i] < s2[i])
            return s1[i] - s2[i];
        i++;
    }
    if (s1[i] > s2[i])
        return my_strlen(s1) - my_strlen(s2);
    if (s1[i] < s2[i])
        return my_strlen(s1) - my_strlen(s2);
    return 0;
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, char *src)
{
    int dest_size = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_size + i] = src[i];
        i++;
    }
    dest[dest_size + i] = '\0';
    return dest;
}

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (new_str == NULL)
        return NULL;
    my_strcpy(new_str, str);
    return new_str;
}
