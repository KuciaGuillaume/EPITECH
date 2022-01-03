/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** is_digit.c
*/

int is_digit(char c)
{
    if ('0' <= c && c <= '9') {
        return 1;
    }
    return 0;
}
