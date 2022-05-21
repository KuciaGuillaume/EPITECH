/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/
#include "../../../include/tetris.h"

Location location_create(float x, float y)
{
    Location location = {0};

    location.x = x;
    location.y = y;
    return location;
}