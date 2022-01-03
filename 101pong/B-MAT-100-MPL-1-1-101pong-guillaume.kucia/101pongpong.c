/*
** EPITECH PROJECT, 2021
** 101pong
** File description:
** 101pong.c
*/

#include "include/my.h"
#include <stdio.h>

void display_h(void)
{
    printf("USAGE\n");
    printf("    ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    printf("DESCRIPTION\n");
    printf("    x0 ball abscissa at time t - 1\n");
    printf("    y0 ball ordinate at time t - 1\n");
    printf("    z0 ball altitude at time t - 1\n");
    printf("    x1 ball abscissa at time t\n");
    printf("    y1 ball ordinate at time t\n");
    printf("    z1 ball altitude at time t\n");
    printf("    n  time shift (greater than or equal to zero, integer)\n");
}

void calc_my_float(struct pong *vector, char *str)
{
    if (str[vector->e] == '-') {
        vector->a = 1;
        vector->e += 1;
    }
    if (vector->a == 1) {
        vector->xx *= 10.00;
        vector->int_xx = str[vector->e] - 48;
        vector->xx += (vector->int_xx);
        vector->e += 1;
    } else {
        vector->xx *= 10.00;
        vector->int_xx = str[vector->e] - 48;
        vector->xx += (vector->int_xx);
        vector->e += 1;
    }
}

float create_my_float(char *string, struct pong *vector)
{
    char *str = string;
    vector->int_xx = 0;
    vector->xx = 0.00;
    vector->e = 0;
    vector->a = 0;
    vector->i = 0;

    while (str[vector->i] != '\0') {
        if (str[vector->i] == '.') {
            return change_my_str(vector, string);
        }
        vector->i += 1;
    }
    vector->i = 0;
    while (str[vector->e] != '\0') {
        calc_my_float(vector, str);
    }
    if (vector->a != 0)
        vector->xx *= (-1);
    return vector->xx;
}

void write_my_velocity_vector(struct pong *vector)
{
    printf("The velocity vector of the ball is:\n");
    vector->Vx = (vector->x1 - (vector->x0));
    vector->Vy = (vector->y1 - (vector->y0));
    vector->Vz = (vector->z1 - (vector->z0));
    printf("(%.2f, %.2f, %.2f)\n", vector->Vx, vector->Vy, vector->Vz);
}

void pong_(char **argv)
{
    struct pong vector;
    if (my_strcmp(argv[1], "-h") == 0) {
        display_h();
    } else {
        vector.x0 = create_my_float(argv[1], &vector);
        vector.y0 = create_my_float(argv[2], &vector);
        vector.z0 = create_my_float(argv[3], &vector);
        vector.x1 = create_my_float(argv[4], &vector);
        vector.y1 = create_my_float(argv[5], &vector);
        vector.z1 = create_my_float(argv[6], &vector);
        vector.n = create_my_float(argv[7], &vector);
        write_my_velocity_vector(&vector);
        write_my_time_t(&vector);
    }
}

