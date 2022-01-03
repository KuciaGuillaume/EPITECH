int number(char **str_ptr);
int my_strtol(char *str, char **endptr);
int summands(char **str_ptr);
int factors(char **str_ptr);

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

int main()
{
    char *str1 = "1";
    char *str2 = "1230";
    char *str3 = "123A0";
    char *str4 = "A";
    char *str5 = "d12";
    char *str6 = "-2";

    assert(number(&str1) == 1);
    assert(number(&str2) == 1230);
    assert(number(&str3) == 123);
    assert(number(&str4) == 0);
    assert(number(&str5) == 0);
    assert(number(&str6) == -2);

    printf("\033[32mint number(char **str_ptr) -> OK\033[0m\n");

    char **end_ptr = (char **)malloc(sizeof(char *));
    char *str1_b = "1";
    char *str2_b = "1230";
    char *str3_b = "123A0";
    char *str4_b = "A";
    char *str5_b = "d12";
    char *str6_b = "-2";
    assert(my_strtol(str1_b, end_ptr) == 1);
    assert(!strcmp(*end_ptr, ""));
    assert(my_strtol(str2_b, end_ptr) == 1230);
    assert(!strcmp(*end_ptr, ""));
    assert(my_strtol(str3_b, end_ptr) == 123);
    assert(!strcmp(*end_ptr, "A0"));
    assert(my_strtol(str4_b, end_ptr) == 0);
    assert(!strcmp(*end_ptr, "A"));
    assert(my_strtol(str5_b, end_ptr) == 0);
    assert(!strcmp(*end_ptr, "d12"));
    assert(my_strtol(str6_b, end_ptr) == -2);
    assert(!strcmp(*end_ptr, ""));

    printf("\033[32mint my_strtol(char *str, char **endptr) -> OK\033[0m\n");

    char *str1_c = "42";
    char *str2_c = "42+42";
    char *str3_c = "42-42";
    char *str4_c = "42+10";
    char *str5_c = "42-1";
    assert(summands(&str1_c) == 42);
    assert(summands(&str2_c) == 84);
    assert(summands(&str3_c) == 0);
    assert(summands(&str4_c) == 52);
    assert(summands(&str5_c) == 41);

    printf("\033[32mint summands(char **str_ptr) -> OK\033[0m\n");

    char *str1_d = "42";
    char *str2_d = "42*42";
    char *str3_d = "42/42";
    char *str4_d = "42*10";
    char *str5_d = "42/1";
    char *str6_d = "42/0";
    assert(factors(&str1_d) == 42);
    assert(factors(&str2_d) == 42 * 42);
    assert(factors(&str3_d) == 42 / 42);
    assert(factors(&str4_d) == 42 * 10);
    assert(factors(&str5_d) == 42 / 1);
    assert(factors(&str6_d) == 0);

    printf("\033[32mint factors(char **str_ptr) -> OK\033[0m\n");

    printf("\033[32m\nAll tests passed, good job!\n");
    free(end_ptr);
}