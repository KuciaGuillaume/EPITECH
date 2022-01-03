/*
** EPITECH PROJECT, 2021
** Bootstrap
** File description:
** mainKarim.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int number(char **str_ptr)
{
    int i = 0;
    int result = 0;

    while ((*str_ptr)[i] != '\0') {
        if ((*str_ptr)[i] >= '0' && (*str_ptr)[i] <= '9') {
            result = result * 10;
            result = result + (*str_ptr)[i] - 48;
            i += 1;
        } else {
            *str_ptr = (&(*str_ptr)[i]);
            return result;
        }
    }
    *str_ptr = (&(*str_ptr)[i]);
    return result;
}

int my_strtol(char *str, char **endptr)
{
    *endptr = str;
    return number(endptr);
}

int summands(char **str_ptr)
{
    int i = 0;
    int result = 0;
    char sign;

    while ((*str_ptr)[0] != '\0') {
        sign = (*str_ptr)[0];
        if (sign == '+') {
            *str_ptr += 1;
            result += number(str_ptr);
        }
        if (sign == '-') {
            *str_ptr += 1;
            result -= number(str_ptr);
        }
        if (sign != '-' && sign != '+') {
            result += number(str_ptr);
        }
    }
    return result;
}

int factors(char **str_ptr)
{
    int i = 0;
    int result = 0;
    char sign;

    while ((*str_ptr)[0] != '\0') {
        sign = (*str_ptr)[0];
        if (sign == '*') {
            *str_ptr += 1;
            result = result * number(str_ptr);
        }
        if (sign == '/') {
            *str_ptr += 1;
            result = result / number(str_ptr);
        }
        if (sign == '%') {
            *str_ptr += 1;
            result = result % number(str_ptr);
        }
        if (sign != '*' && sign != '/' && sign != '%') {
            result += number(str_ptr);
        }
    }
    return result;
}

void check(int (*f)(char **), char *str, int expected_n,
           char *expected_remains) {
  char *remains = str;
  int n = f(&remains);
  bool success = true;
  if (n != expected_n) {
    printf("WRONG number : expected : %d, got : %d\n", expected_n, n);
    success = false;
  }
  if (strcmp(expected_remains, remains) != 0) {
    printf("WRONG remains : expected : %s, got : %s\n", expected_remains,
           remains);
    success = false;
  }
  if (success) {
    printf("SUCCESS\n");
  }
}

void check_number(char *str, int expected_n, char *expected_remains) {
  check(number, str, expected_n, expected_remains);
}

void check_summands(char *str, int expected_n, char *expected_remains) {
  check(summands, str, expected_n, expected_remains);
}

void check_factors(char *str, int expected_n, char *expected_remains) {
  check(factors, str, expected_n, expected_remains);
}

int main() {
  check_number("1", 1, "");
  check_number("12", 12, "");
  check_number("123", 123, "");
  check_number("34+12", 34, "+12");

  check_summands("34+12", 46, "");
  check_summands("34+12-20", 26, "");
  check_summands("34+12-20+30", 56, "");

  check_factors("34*12", 408, "");
  check_factors("34*12/2", 204, "");
  check_factors("34*12/2%30", 24, "");
  return 0;
}