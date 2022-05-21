/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef COREWAR_H
    #define COREWAR_H
    #include "../../common/include/common.h"

typedef struct s_champion champion_t;
typedef struct s_process process_t;
typedef struct s_field field_t;
typedef struct s_vm vm_t;
typedef struct s_corewar corewar_t;
typedef char fieldtype_t;
typedef struct s_read_champ read_champ_t;
typedef struct instruction_s instruction_t;

struct s_champion {

    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int prog_size;
    int id;
    int fd;
};

struct s_process {

    int registries[REG_NUMBER];
    int pc;
    int carry;
    int cycle;
    int live;
    process_t *next;

};

struct s_field {

    int owner_id;
    fieldtype_t type;
    u_char value;

};

struct s_vm {

    field_t fields[MEM_SIZE];
    int cycles;
    int check_interval;
    int lastcheck;
    int checks_passed;
    process_t *processes;
    int is_winner;

};

struct s_corewar {

    vm_t *vm;
    list_t *champions;

};

struct s_read_champ {

    field_t *field;
    int len;

};

enum fieldtype {

    NONE,
    OPCODE,
    PCB,
    PARAMETER

};

struct instruction_s {
    int opcode;
    char name[6];
    int nb_params;
    int params_type[3];
    int cycles;
};

void load_champions(corewar_t *corewar, char **argv);
vm_t *init_vm(void);
void destroy_vm(vm_t *vm);
corewar_t *init_corewar(char **argv);
int destroy_corewar(corewar_t *corewar);
void start_graphic_mode(corewar_t *corewar);

read_champ_t *read_champ(champion_t *champion);

//! REMOVE
int main_graphic_curse(field_t *fields);

instruction_t *get_instruction(field_t *field, int pos);

#endif // COREWAR_H