/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** Day08 task04
*/

#include <stdio.h>

#include <stdlib.h>

int my_putstr(char const *str);

int calculate_word(char const *str, int D)
{
    int i = D;
    int s = 0;
    int taille = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 0 && str[i] < 48) || (str[i] > 57 && str[i] < 65) ||
        (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] <= 127)) {
                i += 1;
        } else {
            taille += 1;
            i += 1;
        }
    }
    return taille;
}

char *separate_word(char const *str, int D)
{
    int i = D;
    int f = 0;
    int s = 0;
    int taille = calculate_word( str, D);
    int number = number_word( str);
    char *word = malloc(((sizeof(char)) * taille) + number);

    while (str[i] != '\0') {
        if ((str[i] >= 0 && str[i] < 48) || (str[i] > 57 && str[i] < 65) ||
        (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] <= 127)) {
            if (s != 0) {
                word[f] = '\n';
                s = 0;
                i += 1;
                f += 1;
            } else {
                i += 1;
            }
        } else {
            word[f] = str[i];
            i += 1;
            f += 1;
            s += 1;
        }
    }
    word[f - 1] = '\0';
    return word;
}

int number_word( char const *str)
{
    int i = 0;
    int taille = 0;
    int number_word = 0;
    int LorNot = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 0 && str[i] < 48) || (str[i] > 57 && str[i] < 65) ||
        (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] <= 127)) {
            if (taille != 0) {
                number_word += 1;
                taille = 0;
            } else {
                LorNot = 0;
                i += 1;
            }
        } else {
            LorNot = 1;
            taille += 1;
            i += 1;
        }
    }
    if (LorNot > 0) {
        number_word += 1;
    }
    return number_word;
}

char **my_str_to_word_array(char const *str)
{
    int D = 0;
    int i = 0;
    int e = 0;
    int taille = 0;
    int mot = 0;
    char *word = separate_word( str, D);
    int number = number_word( str);
    char **tableau = malloc((sizeof(char *) * number) + 1);

    while (number != 0) {
        tableau[number - 1] = malloc((sizeof(char) * taille));
        number -= 1;
    }

    while (word[i] != '\0') {
        if (word[i] != '\n') {
            tableau[D][e] = word[i];
            i += 1;
            e += 1;
        } else {
            e = 0;
            i += 1;
            D += 1;
        }
    }
    tableau[D] = NULL;
    return tableau;
}
