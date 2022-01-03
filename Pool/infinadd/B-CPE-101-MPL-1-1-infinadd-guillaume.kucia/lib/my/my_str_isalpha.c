/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_str_isalpha.c
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 65 &&str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            i += 1;
        } else {
            return 0;
        }
    }
    return 1;
}
