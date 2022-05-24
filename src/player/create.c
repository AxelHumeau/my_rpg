/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create player
*/

#include "my_rpg.h"

static void add_specificities(game_object_t *player)
{
    player->type = PLAYER;
    player->speed = create_vector(5, 5);
    player->saved_anim = 0;
    player->idle = true;
    player->attk_speed = 0.8;
    player->mage_speed = 1;
    player->mana = 200;
    player->xp = 0;
    player->damage = 11;
    player->mage_dmg = 6;
    player->reach = 50;
    player->mana_recovery = 1;
    create_mana_bar(player, 0);
    create_xp_bar(player, 0);
}

game_object_t *create_player(game_t *game)
{
    game_object_t *player = create_game_object(game->assets_texture,
        create_vector(WIDTH / 2, HEIGHT / 2), create_rect(415, 750, 45, 52),
        (sfVector2f) {1.5, 1.5});

    player->hp = 150;
    create_hp_bar(player, 1);
    add_specificities(player);
    sfSprite_setOrigin(player->sprite, (sfVector2f) {16, 25});
    return player;
}
