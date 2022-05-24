/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** move player with animation
*/

#include "my_rpg.h"
#include "rects.h"
#include "particles.h"

static void walking(game_object_t *player, game_t *game)
{
    static float saved_clock;

    if (player->state == IDLE) {
        player->rect.left = 415;
        sfSprite_setTextureRect(player->sprite, player->rect);
        return;
    }
    player->rect.top = RECTS[player->state].top;
    sfSprite_setTextureRect(player->sprite, player->rect);
    if (get_time_clock(game->clock[PLAYER_C]) - saved_clock > 0.1) {
        if (player->rect.left < RECTS[player->state].left_max) {
            player->rect.left += player->rect.width + 19;
            sfSprite_setTextureRect(player->sprite, player->rect);
        } else {
            player->rect.left = 415;
            sfSprite_setTextureRect(player->sprite, player->rect);
        }
        saved_clock = get_time_clock(game->clock[PLAYER_C]);
    }
}

static void move_up_down(game_object_t *player, controls_t ctrl, game_t *game)
{
    static float saved_clock = 0;

    if (get_time_clock(game->clock[PLAYER_C]) - saved_clock > 0.005) {
        if (sfKeyboard_isKeyPressed(ctrl.up)) {
            player->state = WALK_UP;
            player->position.y -= player->speed.y;
            walk_particles(game, 0, 0);
            saved_clock = get_time_clock(game->clock[PLAYER_C]);
        }
        if (sfKeyboard_isKeyPressed(ctrl.down)) {
            player->state = WALK_DOWN;
            player->position.y += player->speed.y;
            walk_particles(game, 0, 0);
            saved_clock = get_time_clock(game->clock[PLAYER_C]);
        }
    }
}

static void move_left_right(game_object_t *player, controls_t ctrl,
game_t *game)
{
    static float saved_clock = 0;

    if (get_time_clock(game->clock[PLAYER_C]) - saved_clock > 0.005) {
        if (sfKeyboard_isKeyPressed(ctrl.left)) {
            player->state = WALK_LEFT;
            player->position.x -= player->speed.x;
            walk_particles(game, 0, 0);
            saved_clock = get_time_clock(game->clock[PLAYER_C]);
        }
        if (sfKeyboard_isKeyPressed(ctrl.right)) {
            player->state = WALK_RIGHT;
            player->position.x += player->speed.x;
            walk_particles(game, 0, 0);
            saved_clock = get_time_clock(game->clock[PLAYER_C]);
        }
    }
}

void move_player(game_object_t *player, controls_t ctrl, game_t *game)
{
    if (!sfKeyboard_isKeyPressed(ctrl.left) &&
        !sfKeyboard_isKeyPressed(ctrl.right) &&
        !sfKeyboard_isKeyPressed(ctrl.down) &&
        !sfKeyboard_isKeyPressed(ctrl.up))
        player->state = IDLE;
    move_up_down(player, ctrl, game);
    move_left_right(player, ctrl, game);
    walking(player, game);
}
