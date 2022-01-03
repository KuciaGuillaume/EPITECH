/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** DAY04 Task03
*/

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return (a);
}
