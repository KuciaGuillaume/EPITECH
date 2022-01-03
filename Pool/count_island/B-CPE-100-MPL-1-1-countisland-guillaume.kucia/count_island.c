/*
** EPITECH PROJECT, 2021
** count_island
** File description:
** count_island.c
*/

#include <stddef.h>
#include <stdio.h>

int size( char **world)
{
    int i = 0;
    while (world[i] != NULL) {
        i += 1;
    }
    return i;
}

void propa( char **world, int verticale, int horizontale)
{
    world[verticale][horizontale] = '0';
}

int count_island(char **world)
{
    int horizontale = 0;
    int verticale = 0;
    int island_number = 0;

    while (verticale != size(world)) {
        while (world[verticale][horizontale] != '\0') {
            if (world[verticale][horizontale] != 'X') {
                horizontale += 1;
            } else {
                propa( world, verticale, horizontale);
                island_number += 1;
            }
        }
        world[verticale][horizontale] = '\n';
        verticale += 1;
        horizontale = 0;
    }
    return island_number;
}
