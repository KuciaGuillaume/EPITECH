/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef LOCATION_H
    #define LOCATION_H

typedef struct s_location Location;

struct s_location {

    float x;
    float y;

};

Location location_create(float x, float y);

#endif //LOCATION_H