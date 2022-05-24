/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include "my_rpg.h"

static void init_inventory_slots(game_t *game, int pos_x, int second_pos_x)
{
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        game->inventory->is_place_taken[i] = false;
        game->inventory->tmp_item_pos[i] = create_vector(0, 354);
        game->inventory->item_pos[i].x = pos_x;
        game->inventory->item_pos[i].y = 354;
        game->inventory->second_item_pos[i].x = second_pos_x;
        game->inventory->second_item_pos[i].y = 440;
        game->inventory->damage[i] = 0;
        game->inventory->atck_speed[i] = 0;
        game->inventory->health[i] = 0;
        game->inventory->mana[i] = 0;
        pos_x += 83;
        second_pos_x += 83;
    }
}

void malloc_init(game_t *game)
{
    game->inventory = malloc(sizeof(inventory_t));
    game->inventory->damage = malloc(sizeof(int) * INVENTORY_SLOTS);
    game->inventory->atck_speed = malloc(sizeof(int) * INVENTORY_SLOTS);
    game->inventory->health = malloc(sizeof(int) * INVENTORY_SLOTS);
    game->inventory->mana = malloc(sizeof(int) * INVENTORY_SLOTS);
    game->inventory->item_pos = malloc(sizeof(sfVector2f) * INVENTORY_SLOTS);
    game->inventory->second_item_pos = malloc(sizeof(sfVector2f)
    * INVENTORY_SLOTS);
    game->inventory->tmp_item_pos = malloc(sizeof(sfVector2f)
    * INVENTORY_SLOTS);
    game->inventory->is_place_taken = malloc(sizeof(bool) * INVENTORY_SLOTS);
    game->inventory->tmp_item = malloc(sizeof(sfSprite *) * INVENTORY_SLOTS);
}

void init_inventory(game_t *game)
{
    int pos_x = 585;
    int second_pos_x = 4;

    malloc_init(game);
    game->inventory->index = 0;
    game->inventory->inventory =
    init_texture_sprite(game->inventory_texture);
    game->inventory->item1 = init_texture_sprite(game->item_texture);
    game->inventory->is_moving = false;
    game->inventory->is_inventory_active = false;
    game->inventory->inventory_timer = sfClock_create();
    game->inventory->count_item_inventory = 0;
    game->bonus_health = 0;
    init_inventory_slots(game, pos_x, second_pos_x);
}
