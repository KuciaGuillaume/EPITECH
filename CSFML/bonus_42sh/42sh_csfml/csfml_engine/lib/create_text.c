/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** create_text.c
*/

#include "my.h"
#include "engine.h"

text_t initiate_text(char *text, char *tag)
{
    static int id = 0;
    text_t create_text;

    create_text.text = sfText_create();
    create_text.id = id;
    create_text.tag = tag;
    create_text.display = true;
    create_text.exist = true;
    create_text.font_size = 15;
    create_text.color = sfBlack;
    sfText_setColor(create_text.text, sfBlack);
    sfText_setCharacterSize(create_text.text, 15);
    sfText_setFont(create_text.text, sfFont_createFromFile("csfml"
    "_engine/font/Yellow Candy.otf"));
    sfText_setString(create_text.text, text);
    id++;
    return create_text;
}

text_t create_text(char *text, char *tag)
{
    node_text_t *new_node = malloc(sizeof(node_text_t));
    text_t create_text = initiate_text(text, tag);
    node_text_t *copy = NULL;

    if (engine.game.text != NULL) {
        copy = engine.game.text;
        for (; copy->next; copy = copy->next)
        new_node->previous = copy;
        new_node->next = NULL;
        new_node->settings = create_text;
        copy->next = new_node;
    } else {
        engine.game.text = malloc(sizeof(node_text_t));
        engine.game.text->previous = NULL;
        engine.game.text->next = NULL;
        engine.game.text->settings = create_text;
    }
    return create_text;
}
