/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../include/corewar.h"

START_FUNC_DEF

void start_corewar(corewar_t *corewar)
{
    vm_t *vm = corewar->vm;

    // for (int i = 0; i < MEM_SIZE; i++) {
    //     printf("%02X", vm->fields[i].value);
    //     printf((i + 1) % 64 == 0 ? "\n" : " ");
    // }
    // main_graphic_curse(corewar->vm->fields);
    instruction_t *instruction = get_instruction(vm->fields, 0);
    if (!instruction) {
        my_printf("Error: Invalid Opcode\n");
        return;
    }
}

int main(int argc, char **argv)
{
    corewar_t *corewar = init_corewar(argv);
    int *n = (int *)my_calloc(sizeof(int));

    START_FUNC
    destroy_corewar(corewar);
    return 0;
}