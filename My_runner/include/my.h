/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Glyph.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <SFML/Audio.h>

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
struct init_s
{
    int type;
    sfVector2f size;
    sfIntRect rect;
    sfVector2f offset;
    float speed;
    int reset;
    sfVector2f scale;
    int identity_type;
    int is_drawing;
    int down;
    int obstacles;
};
typedef struct init_s init_t;
struct obj_s
{
    sfTexture *texture;
    sfSprite* sprite;
    init_t value;
    sfClock* clock;
};
typedef struct obj_s obj_t;
typedef struct node_s node_t;
struct node_s
{
    obj_t *value;
    node_t *next;
    node_t *previous;
};
struct perso_s
{
    sfVector2f offset;
    sfVector2f info_pos;
};
typedef struct perso_s perso_t;

struct score_s
{
    sfClock *clock;
    sfFont *police;
    sfText *score;
    int n;
    char *text;
    int best_score;
    sfText *best_score_text;
};
typedef struct score_s score_t;

struct button_s
{
    int PLAY;
    int game_play;
    int quit_score;
    int back_to_menu;
    int REPLAY;
    int home_map;
};
typedef struct button_s button_t;
struct sound_s
{
    sfMusic *background;
};
typedef struct sound_s sound_t;
struct static_s
{
    int get_collisions;
    int get_collisions_nothing;
    int get_rect;
    int get_rect_type_10;
    int get_rect_menu;
    int get_rect_top;
    float jump_up;
    float jump_drop;
    int jump_a;
    int jump_e;
    int nothing;
    int draw_best_score;
};
typedef struct static_s static_t;
struct window_s
{
    sfRenderWindow* window;
    int JUMMODE;
    int double_JUMP;
    int jump_up;
    int MENU;
    int spawn_reset;
    int life;
    int fly;
    int end_game;
    float difficulty;
    float speed;
    float multiply;
    char *filepath_map;
    int save_y;
    char *filepath_score;
    sound_t sound;
    sfClock *clock;
    static_t statics;
    button_t button;
    perso_t perso;
    score_t score;
};
typedef struct window_s window_t;
struct pointer_s
{
    void (*draw_object) (node_t *);
    void (*box_button) (node_t *);
};
typedef struct offset_s offset_t;
struct offset_s
{
    int x;
    int y;
    int z;
    int reset;
};
typedef struct pointer_s pointer_t;
void destroy_object(node_t *node, window_t *window);
void create_object_push_it_to_list(char *path_to_spritesheet,
init_t value, node_t **node);
int game_event(window_t *all, node_t *node);
void add_node(node_t **node, obj_t *obj_t);
int game_loop(window_t *all, node_t *node);
void foreach(node_t *node, window_t *window, void (*pointer)(node_t *,
window_t *));
void draw_object(node_t *node, window_t *window);
int my_strcmp(char *s1, char *s2);
int my_strlen(char const *str);
void move_type1_2(node_t *node, window_t *window);
void rect_type_3(node_t *node, window_t *window);
void box_button(node_t *node, window_t *window);
void rect_type_10(node_t *node, window_t *window);
void reset_perso(node_t *node, window_t *window);
int load_map(node_t **node, char *filepath, window_t *window);
int set_objects_1(node_t **node, char *filepath, window_t *window);
void set_objects_2_1(node_t **node);
int my_putstr(char const *str);
void my_putchar(char c);
void set_assets_2(node_t **node, int e, char *map, offset_t *offsets);
void jump(window_t *window, node_t *node);
void rect_life(window_t *window, node_t *node);
void initiate_window(window_t *window);
char *my_calloc(char *str, int n);
char *my_itoa(int n, int space);
void draw_score(window_t *window);
void set_game_status(window_t *window, node_t *node);
void destroy_reset(node_t *node, window_t *window, int i);
void get_collisions_nothing(window_t *window, node_t *node);
void get_collisions_large_spike(window_t *window, node_t *node);
void informations(void);
void draw_object_2(window_t *window, node_t *node);
void intersection(window_t *window, node_t *node);
void intersection_rect(window_t *window, node_t *node, sfTime time);
void intersection_rect_10(window_t *window, node_t *node, float seconds);
int my_getnbr(char const *str);
int size_of_int(int n);
void read_write_score(window_t *window);
void set_difficulty(window_t *window);
int find_line_size(char *map);
int map_size(char *map);
void set_assets_nothing_up(node_t **node, int e, char *map, offset_t *offsets);
int game_event_maps(window_t *window, sfEvent *event, node_t *node);

#endif
