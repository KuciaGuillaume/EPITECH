/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** informations.c
*/

#include "../include/my.h"

void informations_player_actions(void)
{
    my_putstr("\033[40m\nPLAYER ACTIONS\033[0m : \n"
    "\n| -> SPACE (Jump)\n"
    "| -> (SPACE X 2) (Double jump)\n"
    "| -> ((SPACE X 2) + SPACE..........) (Double jump and flutter)\n"
    "| -> (P) (Pause)\n");
}

void informations_gameplay(void)
{
    my_putstr("------------------\n");
    my_putstr("| -> \033[40m\033[1;35mGAMEPLAY\033[0m <- |");
    my_putstr(" This section will inform you about the game"
    " \033[92mfeatures\033[0m and \033[92mtips\033[0m.");
    my_putstr("\n------------------\n"
    "\n\033[40mGAME DESCRIPTION\033[0m : \n"
    "MY_RUNNER is a runner type game where the player must reach the \n"
    "end of the level, of course, the map is full of obstacles and the\n"
    "player must avoid them.\n\n"
    "\033[40mINFINITE GAME MODE\033[0m : \n"
    "The infinite game mode has, as the name suggests, no end. The\n"
    "winner is chosen by the player achieving the highest score\n"
    "before his death!"
    "\n\n\033[40mBEST SCORE\033[0m :\nEach map has a better independent "
    "save score\n");
    informations_player_actions();
}

void informations_map_additional(void)
{
    my_putstr("You have just seen an example of a simple map to create ..."
    "\nTo be able"
    " to make advanced maps we advise you to see the examples of maps in "
    "lib / Assets / Contents /\n\n\033[40m\033[1;35mADDITIONAL INFORMATION"
    "\033[0m\n");
    my_putstr("- The is no limit to the number of characters per line, but\n"
    " please make sure that each line gets the same amount ! (this will not\n"
    " disrupt the game, but the map will not render as desired.\n\n"
    "- You don't need to create a big map yourself (no matter how big you\n"
    " define it, the result will be infinite, expect in the ""limited"" game\n"
    " mode). the map works as a loop !\n\n"
    "- Even if the map modification is quite free, you will not be able to\n"
    " create a map with a width smaller than 5. This is to avoid the\n"
    " appearance of texture inside your field of view.\n");

}

void informations_map(void)
{
    my_putstr("------------------\n");
    my_putstr("| -> \033[40m\033[1;35mEDIT MAP\033[0m <- |");
    my_putstr(" This section informs you about"
    " \033[92mediting\033[0m the map.");
    my_putstr("\n------------------\n");
    my_putstr(""
    "| \033[36m00000\033[0m000000000000 | -> The \033[36mblue\033[0m zone"
    " represents the\n"
    "| \033[36m00000\033[0m000000000000 |    player's field of vision at the\n"
    "| \033[36m00000\033[0m000000000000 |    start of the game\n"
    "| \033[36m00000\033[0m000000000000 | \n"
    "| \033[36m00000\033[0m000000000000 | -> 0 = NOTHING\n"
    "| \033[36m00000\033[0m000000000000 | -> 1 = GRASS\n"
    "| \033[36m00000\033[0m000000000000 | -> 2 = THREE SPIKES\n"
    "| \033[36m00000\033[0m000000000000 | -> 3 = PLAYER\n"
    "| \033[36m23224\033[0m002444200002 | -> 4 = BIG SPIKE\n"
    "| \033[36m11111\033[0m011111101011 | -> 5 = LARGE SPIKE\n"
    "| \033[36m00000\033[0m500000050500 | -> 1\033[35m0\033[0m1 = area where"
    " the player can fall\n"
    "---------------------\n");
    informations_map_additional();
}

void informations(void)
{
    my_putstr("\n---------------------------------------------------------"
    "----------------------------\n");
    my_putstr("|                                     \033[40m\033[1;35mWEL"
    "COME\033[0m                                       |\n");
    my_putstr("-----------------------------------------------------------"
    "--------------------------\n"
    "Finite runner created with CSFML.\n"
    "USAGE : (./my_runner map.txt (difficulty : 1 -> 50) or (./my_runner -h)\n"
    "if the difficulty value is not specified, it will be 1 by default\n\n");
    my_putstr("|-> Here you can find a lot of information about how the"
    " \033[92mMY_RUNNER\033[1;0m works.\n     (\033[31mFor a better reading, "
    "please"
    " open the terminal in large format\033[0m)\n\n");
    informations_gameplay();
    my_putchar('\n');
    informations_map();
}
