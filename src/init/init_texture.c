/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** init_texture
*/

#include "my_rpg.h"

void init_texture(game_t *game)
{
    game->assets_texture = sfTexture_createFromFile(
        "ressources/Assets.png", NULL);
    game->item_texture = sfTexture_createFromFile(
        "ressources/item1.png", NULL);
    game->inventory_texture = sfTexture_createFromFile(
        "ressources/inventory.png", NULL);
}

void destroy_textures(game_t *game)
{
    sfTexture_destroy(game->assets_texture);
    sfTexture_destroy(game->item_texture);
    sfTexture_destroy(game->inventory_texture);
}
