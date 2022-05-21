/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/corewar.h"

void load_champion(corewar_t *corewar, char *path)
{
    champion_t *champion = (champion_t *)my_calloc(sizeof(champion_t));
    int fd = open(path, O_RDONLY);
    int garbage = 0;
    char c = 0;

    if (fd == -1)
        return;
    if (read(fd, &garbage, 4) != 4 || garbage != COREWAR_EXEC_MAGIC)
        exit(destroy_corewar(corewar));
    if (read(fd, champion->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
        exit(destroy_corewar(corewar));
    read(fd, &garbage, 4);
    if (read(fd, &champion->prog_size, 4) != 4)
        exit(destroy_corewar(corewar));
    if (read(fd, champion->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
        exit(destroy_corewar(corewar));
    read(fd, &garbage, 4);
    champion->prog_size = swap_int32(champion->prog_size);
    champion->fd = fd;
    // ! REMOVE !!
    // ! REMOVE !!
    // ! REMOVE !!
    printf("Champion \"%s\" loaded\n", champion->name);
    printf("Size : %d\n", champion->prog_size);
    printf("Comment : \"%s\"\n", champion->comment);
    printf("\n");
    // ! REMOVE !!
    // ! REMOVE !!
    // ! REMOVE !!
    list_insert_end(&corewar->champions, champion);
}

int count_nbr_of_champions(corewar_t *corewar)
{
    int nbr = 0;
    list_t *champion = corewar->champions;

    while (champion) {
        nbr++;
        champion = champion->next;
    }
    return nbr;
}

void load_champions_in_vm(corewar_t *corewar)
{
    list_t *champions = corewar->champions;
    champion_t *champion = NULL;
    read_champ_t *champ = NULL;
    int number = count_nbr_of_champions(corewar);
    int offset = MEM_SIZE / number;

    if (number == 0)
        exit(destroy_corewar(corewar));
    for (int i = 0; i < number; i++) {
        champion = (champion_t *)champions->value;
        if (champion->prog_size < 1)
            exit(destroy_corewar(corewar));
        champ = read_champ((champion_t *) champions->value);
        if (!champ)
            exit(destroy_corewar(corewar));
        for (int j = 0; j < champion->prog_size; j++) {
            corewar->vm->fields[i * offset + j].value = champ->field[j].value;
            corewar->vm->fields[i * offset + j].owner_id = i + 1;
        }
        free(champ->field);
        free(champ);
        champions = champions->next;
    }
}

void load_champions(corewar_t *corewar, char **argv)
{
    list_t *champions = NULL;
    read_champ_t *champ = NULL;

    while (*argv) {
        if (has_file_extension(*argv, ".cor"))
            load_champion(corewar, *argv);
        *argv++;
    }
    load_champions_in_vm(corewar);
}