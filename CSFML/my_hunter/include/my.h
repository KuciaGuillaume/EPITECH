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
struct btn_opt
{
    char *title;
    int size_width;
    int size_height;
    sfIntRect rect;
    sfVector2f offset;
    int move;
    int status;
    sfTexture* texture;
    sfSprite* sprite;
};
typedef struct btn_opt btn;
struct text
{
    char *title;
    sfVector2f offset;
    char value[5];
    int size;
    sfFont *police;
    sfText *text;
};
typedef struct text text;

struct frm_s
{
    sfRenderWindow* window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfClock *clock_reload;
    sfTime time_reload;
    float seconds_reload;
    sfClock *clock_energy;
    sfTime time_energy;
    float seconds_energy;
    sfVector2i mouse_pos;
    int pass;
    int menu;
    int Mouse_mode;
    int value_score;
    float calc_time_left;
    sfMusic *gun_m;
    sfMusic *slide_m;
    sfMusic *tap_m;
    sfMusic *no_bullet_m;
    sfMusic *reload_shotgun_m;
    sfMusic *clover_m;
    int sound_active;
    int F8;
    int active;
    int energy_up;
    int speed_vector;
    float timer;
};
typedef struct frm_s frm_t;
void analyse_events(sfRenderWindow *window, frm_t *frm, btn *btns, text *dp);
void reload_shotgun(frm_t *frm, btn *btns, text *dp);
void create_button_alive(frm_t *frm, btn *btns);
void set_opt_button(frm_t *frm, btn *btns);
void set_gun_action(frm_t *frm, btn *btns);
void set_gun_move(frm_t *frm, btn *btns);
void set_game_menu(frm_t *frm, int menu, btn *btns, text *dp);
void set_button_action(frm_t *frm, sfEvent event, btn *btns, text *dp);
void set_move_bullet(btn *btns);
void display_bullet(frm_t *frm, btn *btns);
void active_energy_animation(frm_t *frm, btn *btns);
void set_move_energy(frm_t *frm, btn *btns);
void find_collisions(frm_t *frm, btn *btns);
void restart_energy(frm_t *frm, btn *btns);
void restart_energy_2(frm_t *frm, btn *btns);
void restart_energy_3(frm_t *frm, btn *btns);
void set_score(frm_t *frm, text *dp);
void set_gun_shoot(frm_t *frm, sfEvent event, btn *btns);
void create_texture_and_sprite(btn *btns, int i);
void create_police_and_text(text *dp, int i);
void create_music(frm_t *frm);
void set_move_energy_13(frm_t *frm, btn *btns);
void find_collisions_energy2(frm_t *frm, btn *btns);
void verif_life_score(frm_t *frm, btn *btns);
void set_move_energy_14(frm_t *frm, btn *btns);
void find_collisions_energy3(frm_t *frm, btn *btns);
void set_my_score(text *dp);
void cleanup_ressources(frm_t *frm, btn *btns, text *dp);
btn *set_my_btns(void);
void set_game_event_1(frm_t *frm, btn *btns, text *dp);
void set_game_event_2(frm_t *frm, btn *btns, text *dp);
int initialise_value(frm_t *frm, btn *btns);
text *set_my_dp(void);
void display_my_description(char **av);
int my_putstr(char const *str);
void reset_game(frm_t *frm, btn *btns, text *dp);
#endif
