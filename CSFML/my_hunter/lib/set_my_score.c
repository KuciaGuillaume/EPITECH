/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** set_my_score.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "../include/my.h"

char *check_biggest(text *dp, char *buffer)
{
    int i = 0;

    while (i != 5) {
        if (dp[0].value[i] + 48 > buffer[i] + 48)
            return dp[0].value;
        if (dp[0].value[i] + 48 < buffer[i] + 48)
            return buffer;
        i += 1;
    }
    return buffer;
}

void set_my_score(text *dp)
{
    int fd = open("lib/score.txt", O_RDONLY | O_CREAT );
    int bytes;
    char *buffer = malloc(sizeof(char) * (7));
    printf("score = %s\n", dp[0].value);
    bytes = read(fd, buffer, 5);
    buffer[bytes] = '\0';
    buffer = check_biggest(dp, buffer);
    fd = open("lib/score.txt", O_WRONLY | O_TRUNC );
    write(fd, buffer, 5);
    free(buffer);
    close(fd);
}
