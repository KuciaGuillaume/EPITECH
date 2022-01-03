/*
** EPITECH PROJECT, 2021
** POOL DAY
** File description:
** my_getnbr.c
*/

int signe(char const *str)
{
    int i = 0;
    int less = 0;
    int sign = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            less += 1;
        }
        i += 1;
    }
    if ((less % 2) == 1) {
        sign = 1;
    }
    return sign;
}

long int return_number(char const *str)
{
    int mv = 0;
    int writing = 0;
    long int number = 0;

    while (str[mv] != '\0') {
        if (str[mv] >= 48 && str[mv] <= 57) {
            if (writing == 0 || writing == 1) {
                writing = 1;
                number = (number * 10) + (str[mv] - 48);
                mv += 1;
            } else {
                break;
            }
        } else {
            mv += 1;
            if (writing == 1) {
                writing = 2;
            }
        }
    }
    return number;
}

int my_getnbr(char const *str)
{
    long int mv = 0;
    long int result = return_number(str);
    int sign = signe(str);
    int win = 0;

    if (result > 2147483647 || result < -2147483647) {
        return 0;
    }
    win = result;
    if (sign == 1) {
        win = win * (-1);
        return win;
    } else {
        return win;
    }
}
