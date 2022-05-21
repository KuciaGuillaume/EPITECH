/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-flavio.moreno
** File description:
** read_insctructions.c
*/

#include "../../include/corewar.h"

int forced_value[][4] = {
    {42, 42, 42, 42},
    {0, 0, 0, 0},
    {0, 0, 0, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 0, 0, 1},
    {1, 1, 0, 1},
    {0, 2, 2, 1},
    {1, 0, 0, 1},
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 0, 0, 0}
};

void add_insctructions(read_champ_t *champ, int value, int fieldtype)
{
    field_t *field = (field_t *) realloc(champ->field,
                                (champ->len + 1) * sizeof(field_t));

    field[champ->len].owner_id = 0;
    field[champ->len].type = fieldtype;
    field[champ->len].value = value;
    champ->len++;
    champ->field = field;
}

void read_params(read_champ_t *champ, int fd, int size)
{
    unsigned char value = 0;

    for (int i = 0; i < size; i++) {
        read(fd, &value, 1);
        add_insctructions(champ, value, PARAMETER);
    }
}

//
// args :
//  - [0] : fd
//  - [1] : opcode
//  - [2] : is_pcb
//  - [3] : direct_size
//
void read_insctructions(read_champ_t *champ, int args[4])
{
    int pcb_size[3] = {!args[2] ? 2 : 0, 0, 0};
    int size[5] = {0, 1, args[3] / 8, forced_value[args[1]] ? 2 : 4, IND_SIZE};
    int pcb = 0;
    int v = 0;

    if (args[2]) {
        read(args[0], &pcb, 1);
        add_insctructions(champ, pcb, PCB);
    }
    for (int i = 0; i < 3; i++) {
        if (!pcb_size[2 - i])
            pcb_size[2 - i] = (pcb >> ((i + 1) * 2)) & 3;
        if (forced_value[args[1]][2 - i] == 1)
            pcb_size[2 - i] = 4;
        if (forced_value[args[1]][2 - i] == 2 && pcb_size[2 - i] != 1)
            pcb_size[2 - i] = 4;
    }
    for (int i = 0; pcb_size[i]; i++)
        read_params(champ, args[0], size[pcb_size[i]]);
}

read_champ_t *read_champ(champion_t *champion)
{
    read_champ_t *champ = (read_champ_t *) my_calloc(sizeof(read_champ_t));
    char *str = (char *) my_calloc(sizeof(char) * (champion->prog_size + 1));

    champ->field = (field_t *) my_calloc(sizeof(field_t) * champion->prog_size);
    if (read(champion->fd, str, champion->prog_size) != champion->prog_size) {
        free(champ);
        close(champion->fd);
        return (NULL);
    }
    for (int i = 0; i < champion->prog_size; i++)
        champ->field[i].value = str[i];
    champ->len = champion->prog_size;
    // while (read(fd, &c, 1) > 0) {
    //     add_insctructions(champ, (unsigned char) c, OPCODE);
    //     my_printf("OPCODE : %d\n", c);
    //     params[1] = (unsigned char) c;
    //     params[2] = !(c == 1 || c == 9 || c == 12 || c == 15);
    //     params[3] = (c > 9 && c != 13 && c < 16) ? 16 : 32;
    //     read_insctructions(champ, params);
    // }
    close(champion->fd);
    return champ;
}
