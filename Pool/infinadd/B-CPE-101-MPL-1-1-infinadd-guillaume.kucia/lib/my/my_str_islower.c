/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_str_islower.c
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            i += 1;
        } else {
            return 0;
        }
    }
    return 1;

}
