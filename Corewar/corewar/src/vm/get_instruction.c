/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** get_instruction.c
*/

#include "../../include/corewar.h"

instruction_t *instruction_error(instruction_t *instruction)
{
    free(instruction);
    return NULL;
}

int is_a_pcb(int opcode)
{
    return !(opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15);
}

instruction_t *get_instruction(field_t *field, int pos)
{
    instruction_t *instruction =
                    (instruction_t *)my_calloc(sizeof(instruction_t));
    int pcb = 0;

    if (field[pos % MEM_SIZE].value < 1 || field[pos % MEM_SIZE].value > 16)
        return instruction_error(instruction);
    instruction->opcode = field[pos % MEM_SIZE].value;
    printf("OPCODE : %02X\n", instruction->opcode);
    if (is_a_pcb(instruction->opcode)) {
        pcb = field[(pos + 1) % MEM_SIZE].value;
        printf("PCB : %02X\n", pcb);
    }

    return instruction;
}