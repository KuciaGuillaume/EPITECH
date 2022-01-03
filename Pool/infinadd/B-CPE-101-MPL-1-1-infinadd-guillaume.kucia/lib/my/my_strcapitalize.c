/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_strcapitalize.c
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[i] >= 97 && str[i] <= 122) {
        str[0] = str[0] - 32;
        i += 1;
    }
    while (str[i] != '\0') {
        if (((str[i] >= 97 && str[i] <= 122) && (str[i - 1] == ' ' ||
        str[i - 1] == '+') || (str[i - 1] == '-'))) {
            str[i] = str[i] - 32;
            i += 1;
        } else if (((str[i] >= 65 && str[i] <= 90) ||
        (str[i - 1] == '+') || (str[i - 1] == '-'))) {
            str[i] = str[i] + 32;
            i += 1;
        } else {
            i += 1;
        }
    }
    return str;
}
