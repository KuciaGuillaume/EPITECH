/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            i += 1;
        } else {
            return 0;
        }
    }
    return 1;
}
