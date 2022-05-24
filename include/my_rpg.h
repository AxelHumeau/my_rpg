/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** my_rpg
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "rpg_struct.h"
#include <stdio.h>

#define WIDTH 1600
#define HEIGHT 900
#define NB_SCENES 4
#define ENEMY_NB 10
#define STANDARD_B create_rect(0, 0, 170, 50)
#define SMALL_B create_rect(170, 0, 43, 45)
#define ORIGIN_V create_vector(0, 0)
#define V_TAB(x, y) create_vector(x * WIDTH, y * HEIGHT)
#define GET_TAB(i, data) scene->tab[i]->data
#define NO_SCALE create_vector(1, 1)
#define SCALE(x) create_vector(x, x)
#define NB_CLOCKS 11
#define CURRENT_SCENE game->scenes[game->current_scene]
#define PLAYER_FROM_GAME CURRENT_SCENE->objects[CURRENT_SCENE->nb_obj]
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define SPEED_CAM 20
#define BACKGROUND_WIDTH 4800
#define PARALLAX_MOVING 1
#define MANA_RECOVERY 0.15
#define PODS_TAKEN 1

enum CAMERA_MOVES {
    TO_RIGHT,
    TO_LEFT,
    TO_UP,
    TO_DOWN
};

enum CLOCKS {
    PLAYER_C,
    INVENTORY_C,
    ENEMY_C,
    FADE_C,
    PARALLAX_C,
    WASH_MACHINE_C = 8,
    PODS_C,
    CAM_C
};

enum SCENES {
    START_MENU,
    HUB,
    GAME_OVER,
    CREDITS,
};

enum OBJECT_TYPE {
    UI,
    COLLITION,
    ITEM,
    PODS,
    CAGE,
    ENEMY,
    PLAYER,
    PARALLAX_B,
    PARALLAX_M,
    PARALLAX_F,
    PARALLAX_G,
    WASH_MACHINE,
    OTHER,
};

enum PLAYER_STATE {
    IDLE,
    WALK_UP,
    WALK_RIGHT,
    WALK_DOWN,
    WALK_LEFT,
    SHOOT,
    HIT,
};

/*scene*/
void next_scene(game_t *game, button_t *button);

/*menu*/
void return_to_menu(game_t *game, button_t *button);
void create_settings_button(scene_t *scene, int index, sfFont *font);
void display_settings(game_t *game, button_t *button);

/*idk*/
void do_nothing(game_t *game, button_t *button);
float get_time_clock(sfClock *clock);
char *read_line(FILE *file);
float my_atof(char *str);
void sort_object(game_object_t **objects);
void skip_ending(game_t *game, button_t *button);
void disable_non_near_objects(game_object_t *object);
int get_first_enemy_index(scene_t *scene);
int read_tab_rect_info(int nb_type, FILE *config_file, scene_t *scene);
void update_quest(scene_t *scene, int pods_collected);
void draw_enemy_on_top(game_object_t *player, game_t *game);
int get_res_with_diff(float result, float difficulty, int ratio);
void switch_to_credits(game_t *game);
void decrease_volume(game_t *game, button_t *button);
void increase_volume(game_t *game, button_t *button);

/*basic game*/
void quit_game(game_t *game, button_t *button);
void game_loop(game_t *game);
void resume(game_t *game, button_t *button);
void pause_game(game_t *game);
void pause_b(game_t *game, button_t *button);
void projectile_handle(game_t *game);
void make_bubble(game_t *game);
void inventory_handle(game_t *game);
void get_vector_move(game_t *game, sfVector2f start_pos, int current);
char *read_line(FILE *file);
int set_walls_left(scene_t *scene, int i, int index, game_t *game);
int set_walls_right(scene_t *scene, int i, int index, game_t *game);
int set_walls_up(scene_t *scene, int i, int index, game_t *game);
int set_walls_down(scene_t *scene, int i, int index, game_t *game);
void reset_bubble(game_t *game, int current);
void place_item(game_t *game);
void get_item(game_object_t *player, game_object_t *item, game_t *game);
void remove_item(game_t *game, int i);
void draw_inventory(game_t *game);;

/*enemie*/
void attack_pattern(game_object_t *enemy, game_t *game);
void enemies_animation(game_object_t *enemy, game_t *game);
int is_player_near(game_t *game, game_object_t *enemy);
void enemies_idle(game_object_t *enemy, game_t *game);
sfVector2f random_place(scene_t *scene, int i);

/*player*/
game_object_t *create_player(game_t *game);
void move_player(game_object_t *player, controls_t ctrl, game_t *game);
void make_player_anim(game_t *game, int nb_anim, float time, int top);
void update_player(game_object_t *player, game_t *game);
void player_melee(game_t *game, game_object_t *player);
void player_competences_bubble(game_t *game, button_t *button);
void player_competences_cac(game_t *game, button_t *button);

/*update*/
void update_collision(game_object_t *obj, game_t *game);
void update_default(game_object_t *obj, game_t *game);
void update_bubble(game_t *game, int current);
void update_enemies(game_object_t *obj, game_t *game);
void update_wash(game_object_t *wm, game_t *game);
void update_parallax(game_object_t *obj, game_t *game);
void update_item(game_object_t *obj, game_t *game);
void update_pods(game_object_t *pods, game_t *game);
void update_cage(game_object_t *cage, game_t *game);

/*button*/
button_t *create_button(sfVector2f position, callbacks_func_t *func,
sfIntRect rect, sfText *text);
void draw_button(button_t *button, game_t *game);
void update_button(button_t *button, game_t *game);

/*init*/
void init_sprite_button(button_t *button, sfVector2f position, sfIntRect rect);
void set_secondary_sprite(button_t *button, sfIntRect rect);
void set_tertiary_sprite(button_t *button, sfIntRect rect);
void init_projectile(game_t *game);
sfSprite *init_texture_sprite(sfTexture *texture);
void init_all(game_t *game);
void init_inventory(game_t *game);
void init_controls(game_t *game);
void init_scenes(scene_t *scene, game_t *game);
void init_enemy(game_t *game);
void init_texture(game_t *game);

/*destroy*/
void destroy_button(button_t *button);
void destroy_game_object(game_object_t *obj);
void destroy_game(game_t *game);
void destroy_scenes(scene_t *scene);
void destroy_all_scenes(scene_t **scenes);
void destroy_clocks(sfClock **clocks);
void destroy_textures(game_t *game);

/*create*/
sfVector2f create_vector(float x, float y);
sfIntRect create_rect(int x, int y, int width, int height);
sfRenderWindow *create_window(char const *title, unsigned int height,
unsigned int width);
game_object_t *create_game_object(sfTexture *assets_texture,
sfVector2f pos, sfIntRect rect, sfVector2f scale);
game_t *create_game(char *player_name);
void create_hp_bar(game_object_t *object, int is_player);
sfRectangleShape *create_rect_bar(sfVector2f position, int width,
sfColor color, sfVector2f scale);
scene_t **create_scenes(game_t *game);
scene_t *create_menu_scene(game_t *game);
sfText *create_text(const char *str, sfFont *font, sfColor *color, int size);
scene_t *create_hub_scene(game_t *game);
void create_inventory(game_t *game);
sfClock **create_clocks(void);
game_object_t *create_wall(sfVector2f pos, sfIntRect rect, sfTexture *texture);
int create_enemy(scene_t *scene, int i, int index, game_t *game);
scene_t *create_game_over_scene(game_t *game);
game_object_t *create_washing_machine(game_t *game);
void set_parallax(scene_t *scene, int index, game_t *game);
scene_t *create_credit_scene(game_t *game);
int create_item(scene_t *scene, int i, int index, game_t *game);
button_t *create_quest_button(sfFont *font);
void create_mana_bar(game_object_t *object, int is_player);
void create_xp_bar(game_object_t *object, int is_player);
game_object_t *create_pods(sfVector2f pos, sfIntRect rect, game_t *game);
game_object_t *create_cage(game_t *game);

/*hud*/
void update_bars(game_object_t *object, sfRenderWindow *window);

/*event*/
sfBool is_mouse_over_button(button_t *button, sfRenderWindow *window);
sfBool is_button_pressed(button_t *button, sfRenderWindow *window);
void check_events(game_t *game);
void check_escape(game_t *game);

/*draw and print*/
void draw_object(game_t *game);
void refresh_scene(game_t *game);

/*draw walking particles*/
void walk_particles(game_t *game, int dx, int dy);
void display_framebuffer(game_t *game);
void fade(game_t *game);

/*camera*/
void move_camera(scene_t *scene, game_t *game, int dir);
int check_player_position(game_object_t *player, game_t *game);

/*collision*/
void hard_collision(game_object_t *object, game_t *game);
bool test_colliding(sfFloatRect rect_1, sfFloatRect rect_2);
