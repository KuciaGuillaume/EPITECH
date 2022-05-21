/*
** EPITECH PROJECT, 2021
** src
** File description:
** main.c
*/

#include "my.h"
#include "engine.h"

int main(int ac, char **av, char **env)
{
    return csfml_engine((int[3]){1920, 1080, 32},
    "my_defender", true, env);
    return 0;
}
