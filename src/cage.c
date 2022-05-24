/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** cage
*/

#include "my_rpg.h"

game_object_t *create_cage(game_t *game)
{
    game_object_t *cage = create_game_object(game->assets_texture,
    V_TAB(0.5, 1.66), (sfIntRect) {1097, 259, 51, 100}, SCALE(2));

    cage->type = CAGE;
    sfSprite_setOrigin(cage->sprite, (sfVector2f)
    {cage->rect.width / 2, cage->rect.height / 2});
    return cage;
}

void update_cage(game_object_t *cage, game_t *game)
{
    if (cage->is_disabled)
        return;
    sfSprite_setPosition(cage->sprite, cage->position);
    sfRenderWindow_drawSprite(game->window, cage->sprite, NULL);
    if (game->pods_collected < 3)
        hard_collision(cage, game);
    else if (test_colliding(sfSprite_getGlobalBounds(cage->sprite),
    sfSprite_getGlobalBounds(PLAYER_FROM_GAME->sprite)))
        game->pods_collected++;
}
