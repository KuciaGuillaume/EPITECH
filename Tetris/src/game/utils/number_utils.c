/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

static int my_getnbr_two(char const *str, int i, int *ptr, int number)
{
    if (str[i] >= 48 && str[i] <= 57) {
        number = (number * 10) + (str[i] - 48);
        return number;
    } else if (str[i] == '-') {
        *ptr += 1;
        return number;
    }
    if (str[i] != '+')
        return number;
    return number;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long int number = 0;
    int op = 0;

    while (str[i]) {
        number = my_getnbr_two(str, i, &op, number);
        if (number > 2147483647 || number + 1 < -2147483647)
            return 0;
        i++;
    }
    if (op != 0 && op % 2 == 1)
        return number * -1;
    else
        return number;
}