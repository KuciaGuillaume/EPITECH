/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.kucia
** File description:
** my.h
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef HEADERS
    #define HEADERS
struct storage_s
{
    int t;
    int z;
    int r;
    int s;
    int nflags;
} typedef storage_t;
int main(int ac, char **av);
void display_description(int ac, char **av);
#endif
