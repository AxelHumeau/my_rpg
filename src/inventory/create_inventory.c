/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_inventory.c
*/

#include "my_rpg.h"
#include <stdio.h>

static void check_item(game_t *game)
{
    game->inventory->count_item_inventory += 1;
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        if (game->inventory->is_place_taken[i])
            continue;
        if (i < 7) {
            game->inventory->tmp_item[i] = game->inventory->item1;
            game->inventory->tmp_item_pos[i].x =
            game->inventory->item_pos[i].x;
            game->inventory->tmp_item_pos[i].y = 354;
            game->inventory->is_place_taken[i] = true;
            return;
        } else {
            game->inventory->tmp_item[i] = game->inventory->item1;
            game->inventory->tmp_item_pos[i].x =
            game->inventory->second_item_pos[i].x;
            game->inventory->tmp_item_pos[i].y = 434;
            game->inventory->is_place_taken[i] = true;
        }
    }
}

void place_item(game_t *game)
{
    if (game->inventory->count_item_inventory != INVENTORY_SLOTS) {
        if (sfClock_getElapsedTime(game->inventory->inventory_timer).
        microseconds > 20000) {
            check_item(game);
            sfClock_restart(game->inventory->inventory_timer);
        }
    }
}

void draw_item(game_t *game)
{
    for (int i = 0; i < game->inventory->count_item_inventory && i < 14; i++) {
        if (i >= 7 && game->inventory->is_place_taken[i]) {
            sfSprite_setPosition(game->inventory->tmp_item[i], (sfVector2f)
            {game->inventory->tmp_item_pos[i].x,
            game->inventory->tmp_item_pos[i].y});
            sfSprite_setScale(game->inventory->tmp_item[i],
            (sfVector2f) {0.2, 0.2});
            sfRenderWindow_drawSprite(game->window,
            game->inventory->tmp_item[i], NULL);
        }
        if (i < 7 && game->inventory->is_place_taken[i]) {
            sfSprite_setPosition(game->inventory->tmp_item[i], (sfVector2f)
            {game->inventory->tmp_item_pos[i].x,
            game->inventory->tmp_item_pos[i].y});
            sfSprite_setScale(game->inventory->tmp_item[i],
            (sfVector2f) {0.2, 0.2});
            sfRenderWindow_drawSprite(game->window,
            game->inventory->tmp_item[i], NULL);
        }
    }
}

void draw_inventory(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->inventory->inventory, NULL);
    draw_item(game);
}

void create_inventory(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue &&
    game->inventory->is_inventory_active == false) {
        game->inventory->is_inventory_active = true;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue &&
    game->inventory->is_inventory_active == true) {
        game->inventory->is_inventory_active = false;
        return;
    }
}
