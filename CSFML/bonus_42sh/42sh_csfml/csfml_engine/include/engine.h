/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** engine.h
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
#include "my.h"
#include <math.h>

#ifndef ENGINE_H
    #define ENGINE_H

    #define V2f sfVector2f
    #define GPT get_position_tag
    #define GPO get_position_obj
    #define GRT get_rotation_tag
    #define SST set_shape_tag
    #define SCT set_scale_tag
    #define SPT set_position_tag
    #define SPO set_position_obj
    #define SPTT set_text_position_text
    #define GPTT get_text_position_text
    #define DELTA engine.delta_time

struct obj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2u size;
    char *tag;
    bool display;
    bool exist;
    bool gravity;
    bool ishape;
    float speed;
    bool mouse_inside;
    sfIntRect shape;
    int display_order;
    float angle;
    int id;
    char *link_tag;
    int link_id;
};
typedef struct obj_s obj_t;

struct text_s
{
    sfText *text;
    int id;
    bool display;
    bool exist;
    int font_size;
    sfColor color;
    char *tag;
};
typedef struct text_s text_t;

struct music_s
{
    sfMusic *sound;
    int id;
    float volume;
    bool playing;
    bool loop;
    char *tag;
};
typedef struct music_s music_t;

typedef struct node_s node_t;
struct node_s
{
    node_t *next;
    node_t *previous;
    obj_t settings;

};

typedef struct node_music_s node_music_t;
struct node_music_s
{
    node_music_t *next;
    node_music_t *previous;
    music_t settings;

};

typedef struct node_text_s node_text_t;
struct node_text_s
{
    node_text_t *next;
    node_text_t *previous;
    text_t settings;
};

struct fps_s
{
    bool view_fps;
    sfClock *elapsed;
    int fps;
    sfText *text;
    sfTime time;
};
typedef struct fps_s fps_t;

struct window_s
{
    sfRenderWindow* window;
    sfRenderWindow* engine;
    sfVideoMode win_mode;
    V2f size;
    char *win_name;
    bool fullscreen;
    int framerate;
    sfVector2i middle_screen;
    obj_t background;
    node_t *parallax;
    fps_t fps;
    sfClock *clock;
    sfTime time;
};
typedef struct window_s window_t;

struct game_s
{
    node_t *list;
    node_text_t *text;
    node_music_t *music;
    bool game_end;
    float gravity;
    int end_value;
};
typedef struct game_s game_t;

struct engine_s
{
    window_t win_settings;
    game_t game;
    sfColor clear_background;
    sfEvent event;
    float delta_time;
};
typedef struct engine_s engine_t;

typedef struct delta_time_s {
    float time;
    float saved;
} delta_time_t;

extern engine_t engine;

void shape_img();
void display_engine();
void window_set_position(sfVector2i offset);
void microprogramme_create();
void primary_function();
void display(int start);
void destroy_all();
void set_background(char *src_img, bool auto_resize);
bool key_pressed(sfKeyCode key);
void game_end(int value);
obj_t create_object(char *src_img, char *flag, int display_order);
void set_scale_tag(char *tag, V2f scale);
void set_scale_obj(obj_t *obj, V2f scale);
V2f get_scale_tag(char *tag);
void set_position_tag(char *tag, V2f offset);
void set_position_obj(obj_t obj, V2f offset);
sfVector2u get_size_tag(char *tag);
sfVector2u get_size_obj(obj_t *obj);
void set_gravity_tag(char *tag, bool gravity);
void set_gravity_obj(obj_t *obj, bool gravity);
V2f get_position_tag(char *tag);
V2f get_position_obj(obj_t obj);
void set_shape_tag(char *tag, sfIntRect shape, bool ishape);
void set_shape_obj(obj_t *obj, sfIntRect shape, bool ishape);
bool get_collision_tag(char *obj_tag, char *obstacles_tag);
void set_parallax(char **src_img, float speed, float multiplicator);
void display_parallax();
void set_visible_tag(char *tag, bool visible);
void set_visible_obj(obj_t *obj, bool visible);
void view_fps();
void set_fps(bool visible, int font_size, sfColor color);
bool mouse_inside_tag(char *tag);
bool mouse_pressed(sfMouseButton button, int *i);
bool mouse_inside_obj(obj_t *obj);
bool elapsed_time_seconds(float seconds, float *increment,
float *save_increment);
bool elapsed_time_milliseconds(float milliseconds,
float *increment, float *save_increment);
bool elapsed_time_microseconds(float microseconds,
float *increment, float *save_increment);
sfIntRect get_shape_tag(char *tag);
sfIntRect get_shape_obj(obj_t *obj);
void animation_tag(char *tag, int *shape_start_increment_end_milliseconds,
float *increment, float *save_increment);
void animation_obj(obj_t *obj, int *shape_start_increment_end_milliseconds,
float *increment, float *save_increment);
void display_obj();
text_t create_text(char *text, char *tag);
void display_text();
void set_text_color_text(text_t *text, sfColor color);
void set_text_color_tag(char *tag, sfColor color);
void set_text_position_text(text_t text, V2f position);
void set_text_position_tag(char *tag, V2f position);
void set_text_text(text_t *text, char *str);
void set_text_tag(char *tag, char *text);
void set_text_size_text(text_t *text, int size);
void set_text_size_tag(char *tag, int size);
void set_text_visible_tag(char *tag, bool visible);
void set_text_visible_text(text_t *text, bool visible);
V2f get_text_position_tag(char *tag);
V2f get_text_position_text(text_t text);
bool key_press(sfKeyCode key);
bool mouse_press(sfMouseButton button);
void exit_program(float time);
sfVector2u get_texture_size_tag(char *tag);
sfVector2u get_texture_size_obj(obj_t *obj);
music_t create_music(char *src_sound, char *tag);
void set_music_play_sfmusic(music_t *sound, bool loop, float volume);
void set_music_play_tag(char *tag, bool loop, float volume);
void set_music_pause_sfmusic(music_t *sound);
void set_music_pause_tag(char *tag);
void set_music_stop_tag(char *tag);
void set_music_stop_sfmusic(music_t *sound);
void set_music_volume_sfmusic(music_t *sound, float volume);
void set_music_volume_tag(char *tag, float volume);
void set_music_loop_tag(char *tag, bool loop);
void set_music_loop_sfmusic(music_t *sound, bool loop);
void destroy_list();
void destroy_music();
int get_collision_obj_id(obj_t *obj, char *obstacles_tag);
int get_collision_tag_id(char *obj_tag, char *obstacles_tag);
obj_t copy_object(int id);
void set_rotation_obj(obj_t *obj, float angle);
void set_rotation_tag(char *tag, float angle);
void destroy_object(int id);
V2f get_scale_obj(obj_t obj);
bool compare_sfvector2f(V2f first, V2f second);
void set_enemy_obj(obj_t *obj, V2f *path, int n);
void set_enemy_tag(char *tag, V2f *path, int n);
V2f *random_this(V2f *value, int n);
obj_t mouse_inside_more(char *tag);
char *format_number(char *str, int str_i);
void set_exits_tag(char *tag, bool exits);
bool get_collision_obj(obj_t *obj, char *obstacles_tag, int decrement);
bool get_exits_tag(char *tag);
bool get_exits_obj(obj_t obj);
sfColor get_sprite_color_tag(char *tag);
obj_t copy_object_tag(char *tag);
void get_elapsed_time(float *increment, float *save_increment);
void set_link_tag(char *tag1, char *tag2);
bool get_text_visible_tag(char *tag);
sfFloatRect get_text_shape_tag(char *tag);
void resize_parallax_hg(obj_t *obj);
bool get_visible_tag(char *tag);
int get_collision_obj_norms(char *obstacles_tag, sfVector2f pos_1,
sfVector2u size_1, int decrement);
int get_collision_tag_norms(char *obstacles_tag, sfVector2f pos_1,
sfVector2u size_1);
float get_rotation_tag(char *tag);
void set_link_id(obj_t *obj1, obj_t *obj2);
int get_collision_zone_tag_id(char *obj_tag, char *obstacles_tag, int zone);
int get_collision_zone_obj_id(obj_t *obj, char *obstacles_tag, int zone);
void resize_my_img(obj_t *obj, V2f new_size);
int get_pv_max_obj(obj_t *obj);
void set_touch_object(obj_t *obj);
void destroy_object_tag(char *tag);
void destroy_text_tag(char *tag);
int mouse_scroll(void);
void set_music_stop_tags(char **tags, int size);
void set_exits_obj(obj_t *obj, bool exits);
sfText *get_text_tag(char *tag);
void destroy_text(text_t *text);
void destroy_texts(void);

#endif // END //
