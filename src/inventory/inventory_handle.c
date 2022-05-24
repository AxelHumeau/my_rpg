/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_inventory.c
*/

#include "my_rpg.h"

static void check_item_to_equip2(game_t *game, sfVector2i pos, int i)
{
    if (pos.x >= game->inventory->second_item_pos[i].x + 100 && pos.x <=
    game->inventory->second_item_pos[i].x + 160
    && pos.y >= game->inventory->second_item_pos[i].y + 20 && pos.y <=
    game->inventory->second_item_pos[i].y + 120 &&
    game->inventory->is_place_taken[i]) {
        game->bonus_damage = game->inventory->damage[i];
        game->bonus_health = game->inventory->health[i];
        game->bonus_attk_speed = game->inventory->atck_speed[i];
        remove_item(game, i);
    }
}

static void check_item_to_equip(game_t *game, sfVector2i pos)
{
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        if (pos.x >= game->inventory->item_pos[i].x + 100 && pos.x <=
        game->inventory->item_pos[i].x + 160
        && pos.y >= game->inventory->item_pos[i].y + 20 && pos.y <=
        game->inventory->item_pos[i].y + 120 &&
        game->inventory->is_place_taken[i]) {
            game->bonus_damage = game->inventory->damage[i];
            game->bonus_health = game->inventory->health[i];
            game->bonus_attk_speed = game->inventory->atck_speed[i];
            remove_item(game, i);
        }
        check_item_to_equip2(game, pos, i);
    }
}

static void dump_item(game_t *game, sfVector2i pos)
{
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        if (pos.x >= game->inventory->item_pos[i].x + 100 && pos.x <=
        game->inventory->item_pos[i].x + 160
        && pos.y >= game->inventory->item_pos[i].y + 20 && pos.y <=
        game->inventory->item_pos[i].y + 120 &&
        game->inventory->is_place_taken[i]) {
            remove_item(game, i);
        }
        if (pos.x >= game->inventory->second_item_pos[i].x + 100 && pos.x <=
        game->inventory->second_item_pos[i].x + 160
        && pos.y >= game->inventory->second_item_pos[i].y + 20 && pos.y <=
        game->inventory->second_item_pos[i].y + 120 &&
        game->inventory->is_place_taken[i]) {
            remove_item(game, i);
        }
    }
}

static void equip_item(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        check_item_to_equip(game, pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyO) == sfTrue)
        dump_item(game, pos);
}

void inventory_handle(game_t *game)
{
    if (game->inventory->is_inventory_active == true) {
        draw_inventory(game);
        equip_item(game);
    }
}
