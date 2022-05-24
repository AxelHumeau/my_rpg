/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** defender_struct
*/

#pragma once

#include "my_rpg.h"
#include "particles.h"
#include <stdbool.h>

#define ENEMY_NB 10
#define PROJ_NB 100
#define INVENTORY_SLOTS 14

typedef struct game game_t;
typedef struct button button_t;
typedef void (callbacks_func_t)(game_t *game, button_t *button);

typedef struct enemies_info_s {
    int cac;
    int health;
    sfVector2f speed;
    int damage;
    float attack_speed;
    int type;
    sfVector2f size;
    char *path_sprite;
    sfIntRect rect;
    int animation;
    int reach;
    int xp;
} enemies_info_t;

typedef struct controls {
    int up;
    int down;
    int right;
    int left;
    int bubble;
    int pause;
    int melee;
    int inventory;
} controls_t;

typedef struct game_object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f normalize;
    sfIntRect rect;
    sfClock *clock;
    int type;
    bool idle;
    bool triggered;
    float attk_speed;
    float mage_speed;
    int state;
    int cac;
    int hp;
    int mage_dmg;
    int animation;
    int mana;
    int xp;
    int mana_recovery;
    float saved_anim;
    float saved_atk;
    float saved_idle;
    float animation_speed;
    int damage;
    int reach;
    sfVector2f speed;
    int is_disabled;
    sfRectangleShape *hp_bar;
    sfRectangleShape *hp_bar_background;
    sfRectangleShape *mana_bar;
    sfRectangleShape *mana_bar_background;
    sfRectangleShape *xp_bar;
    sfRectangleShape *xp_bar_background;
} game_object_t;

typedef struct button {
    callbacks_func_t *callback;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    int status;
    sfIntRect ter_rect;
    sfSprite *sec_sprite;
    sfSprite *ter_sprite;
    sfSprite *auxiliary_sprite;
    int is_disabled;
} button_t;

typedef struct projectile_s {
    sfIntRect rect;
    sfIntRect splash_rect;
    sfSprite *sprite;
    sfSprite *splash;
    sfClock *clock;
    bool auto_target;
    bool is_enemy;
    bool is_shooting;
    bool shoot;
    bool splashing;
    float magnitude;
    int damage;
    int animation;
    sfVector2f target_distance;
    sfVector2f move_v;
    sfVector2f speed;
    sfVector2f target;
    sfVector2f position;
    sfVector2f normalize;
    sfMusic *song;
} projectile_t;

typedef struct inventory_s {
    bool is_inventory_active;
    bool is_moving;
    int index;
    sfVector2f *tmp_item_pos;
    int count_item_inventory;
    sfSprite *inventory;
    sfSprite *item1;
    int *health;
    int *damage;
    int *atck_speed;
    int *mana;
    sfSprite **tmp_item;
    sfVector2f *item_pos;
    sfVector2f *second_item_pos;
    sfClock *inventory_timer;
    bool *is_place_taken;
} inventory_t;

typedef struct info_tab {
    int nb_enemies;
    sfVector2f *enemies_pos;
    bool op_up;
    bool op_down;
    bool op_left;
    bool op_right;
    int *type_enemies;
    float difficulty;
    int type;
    sfIntRect rect;
    sfVector2f pos;
} info_tab_t;

typedef struct scene {
    int nb_tabs;
    int nb_obj;
    info_tab_t **tab;
    button_t **buttons;
    game_object_t **objects;
    sfMusic *music;
} scene_t;

typedef struct game {
    projectile_t *proj[PROJ_NB];
    bool is_camera_moving;
    bool *is_item_placed;
    inventory_t *inventory;
    scene_t **scenes;
    sfClock **clock;
    sfRenderWindow *window;
    int bonus_health;
    int bonus_damage;
    int bonus_attk_speed;
    int bonus_mana;
    int index;
    int current_scene;
    int item_spawned;
    sfFont *font;
    button_t *pause_button;
    int is_paused;
    button_t *resume_button;
    button_t *quit_button;
    button_t *menu_button;
    sfMusic **sound_effects;
    int gold;
    controls_t controls;
    enemies_info_t *nmi_inf[ENEMY_NB];
    fbr_t *framebuffer;
    int volume;
    bool is_invalid;
    sfTexture *assets_texture;
    sfTexture *item_texture;
    sfTexture *inventory_texture;
    int pods_collected;
} game_t;

typedef scene_t *(*scene_creator_t)(game_t *game);
