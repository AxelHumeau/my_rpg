/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_inventory.c
*/

#include <stdio.h>
#include "my_rpg.h"

void remove_item(game_t *game, int i)
{
    game->inventory->is_place_taken[i] = false;
    game->inventory->damage[i] = 0;
}

void get_item(game_object_t *player, game_object_t *item, game_t *game)
{
    int i = 0;

    if (player->position.x >= item->position.x - 20 && player->position.x <=
    item->position.x + 50 && player->position.y >= item->position.y - 10 &&
    player->position.y <= item->position.y + 20) {
        for (; game->inventory->damage[i] != 0 && i < 13; i++);
        place_item(game);
        game->inventory->damage[i] = item->damage;
        game->inventory->health[i] = item->hp;
        game->inventory->atck_speed[i] = item->attk_speed;
        item->idle = true;
        item->position.x = 0;
        item->position.y = 0;
    }
}
