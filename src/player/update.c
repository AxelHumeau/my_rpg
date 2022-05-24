/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** player
*/

#include "my_rpg.h"

static void fight_capacity(game_object_t *player, game_t *game)
{
    static float saved_clock1 = 0;
    static float saved_clock2 = 0;

    if (get_time_clock(game->clock[PLAYER_C]) - saved_clock1 >
        player->mage_speed) {
        if (sfKeyboard_isKeyPressed(game->controls.bubble) == sfTrue) {
            make_bubble(game);
            saved_clock1 = get_time_clock(game->clock[PLAYER_C]);
        }
    }
    if (get_time_clock(game->clock[PLAYER_C]) - saved_clock2 >
        player->attk_speed) {
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
            player_melee(game, player);
            saved_clock2 = get_time_clock(game->clock[PLAYER_C]);
        }
    }
}

static void update_player_col(game_object_t *player, game_t *game)
{
    for (int i = 0; i < PROJ_NB - 1; i++) {
        if (test_colliding(sfSprite_getGlobalBounds(player->sprite),
        sfSprite_getGlobalBounds(game->proj[i]->sprite)) &&
        game->proj[i]->is_enemy && game->proj[i]->is_shooting) {
            player->hp -= game->proj[i]->damage;
            sfMusic_stop(game->sound_effects[1]);
            sfMusic_play(game->sound_effects[1]);
            reset_bubble(game, i);
        }
    }
}

static void update_mana_and_xp_bar(game_object_t *player, game_t *game)
{
    static float saved_clock = 0;

    if (get_time_clock(game->clock[PLAYER_C]) - saved_clock > MANA_RECOVERY) {
        if (sfKeyboard_isKeyPressed(game->controls.bubble) != sfTrue &&
            player->mana < 200)
            player->mana += player->mana_recovery;
        saved_clock = get_time_clock(game->clock[PLAYER_C]);
    }
    if (player->xp == 100) {
        CURRENT_SCENE->buttons[1]->is_disabled = false;
        CURRENT_SCENE->buttons[2]->is_disabled = false;
    } else {
        CURRENT_SCENE->buttons[1]->is_disabled = true;
        CURRENT_SCENE->buttons[2]->is_disabled = true;
    }
}

static void update_player_hud(game_object_t *player, game_t *game)
{
    button_t *button1 = CURRENT_SCENE->buttons[1];
    button_t *button2 = CURRENT_SCENE->buttons[2];

    if (player->hp > 0)
        update_bars(player, game->window);
    if (player->hp <= 0) {
        sfMusic_stop(CURRENT_SCENE->music);
        player->idle = false;
        make_player_anim(game, 6, 0.3, 1515);
        if (player->idle)
            game->current_scene++;
        sfMusic_play(CURRENT_SCENE->music);
    }
    sfRenderWindow_drawSprite(game->window, button1->sec_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, button1->ter_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, button1->auxiliary_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, button2->sec_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, button2->ter_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, button2->auxiliary_sprite, NULL);
}

void update_player(game_object_t *player, game_t *game)
{
    fight_capacity(player, game);
    if (!player->is_disabled) {
        if (!game->is_camera_moving && player->idle)
            move_player(player, game->controls, game);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    if (player->hp + game->bonus_health >= 150)
        player->hp = 150;
    else
        player->hp += game->bonus_health;
    game->bonus_health = 0;
    if (!player->idle)
        make_player_anim(game, 0, 0, 0);
    update_player_col(player, game);
    update_mana_and_xp_bar(player, game);
    update_player_hud(player, game);
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
    draw_enemy_on_top(player, game);
}
