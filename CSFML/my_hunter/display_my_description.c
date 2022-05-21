/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** display_my_description.c
*/

#include "include/my.h"

void display_my_description(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Bienvenue dans My_hunter !\n\n"
        "Le but du jeu est de toucher des boules d'énergies se déplaçant de "
        "gauche à\n"
        "droite ou de droite à gauche (le sens et les lieux de réapparitions"
        " sont générés\n"
        "aléatoirement, sauf au tout début de la partie).\n\n"
        "Vous possédez un fusil avec un maximum de 3 munitions, "
        "qui se recharge\n"
        "au bout d'une seconde à chaque utilisation. Si vous "
        "dépassez les 100 points, \n"
        "le temps de rechargement diminue de -0, 5 secondes, \n\n"
        "Bien évidemment il faut maintenant hausser la "
        "difficulté à un niveau supérieur!\n"
        "Vous disposez d'un maximum de 3 vies, à chaque fois "
        "qu'une boule d'énergie\n"
        "touche un rebord, votre vie diminue alors de -0, 5. Si "
        "votre vie arrive à 0, C'est\n"
        "le game over. Sachez aussi que tous les 100 points votre "
        "vie se régénère de 1!\n");
    }
}