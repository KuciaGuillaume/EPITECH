/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int result = 0;
    int i = 0;
    int sign = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign *= -1;
        }
        i += 1;
    }
    while (str[i]) {
        if (str[i] > 47 && str[i] < 58) {
            result *= 10;
            result += str[i] - 48;
            i += 1;
        } else {
            return (result * sign);
        }
    }
    return (result * sign);
}
