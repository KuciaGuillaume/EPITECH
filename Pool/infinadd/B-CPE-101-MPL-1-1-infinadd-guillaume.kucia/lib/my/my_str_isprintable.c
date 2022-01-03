/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_str_isprintable.c
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126) {
            i += 1;
        } else {
            return 0;
        }
    }
    return 1;
}
