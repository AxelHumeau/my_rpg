/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** projectil_handle
*/

#include "my_rpg.h"
#include <math.h>

void get_vector_move(game_t *game, sfVector2f start_pos, int current)
{
    game->proj[current]->position.x = start_pos.x;
    game->proj[current]->position.y = start_pos.y;
    sfSprite_setPosition(game->proj[current]->sprite,
    game->proj[current]->position);
    game->proj[current]->move_v.x = game->proj[current]->target.x
    - game->proj[current]->position.x;
    game->proj[current]->move_v.y = game->proj[current]->target.y
    - game->proj[current]->position.y;
    game->proj[current]->magnitude = sqrt(pow(game->proj[current]->move_v.x, 2)
    + pow(game->proj[current]->move_v.y, 2));
}

void projectile_handle(game_t *game)
{
    if (!game->is_camera_moving)
        for (int i = 0; i < PROJ_NB; i++)
            update_bubble(game, i);
    else
        for (int i = 0; i < PROJ_NB - 1; i++)
            game->proj[i]->is_shooting = false;
}

static void shoot_bubble(game_t *game, int index)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(game->window);

    game->proj[index]->target.x = (float) tmp.x;
    game->proj[index]->target.y = (float) tmp.y;
    game->proj[index]->is_shooting = true;
    game->proj[index]->shoot = false;
    game->proj[index]->damage = PLAYER_FROM_GAME->mage_dmg;
    game->proj[index]->rect = create_rect(175, 2272, 76, 74);
    sfSprite_setTextureRect(game->proj[index]->sprite,
    game->proj[index]->rect);
    get_vector_move(game, PLAYER_FROM_GAME->position, index);
    game->proj[index]->is_enemy = false;
}

void make_bubble(game_t *game)
{
    int index = 0;

    if (PLAYER_FROM_GAME->mana < 8)
        return;
    PLAYER_FROM_GAME->mana -= 8;
    for (; game->proj[index + 1]; index++)
        if (!game->proj[index]->shoot && !game->proj[index]->is_shooting)
            break;
    sfMusic_stop(game->proj[index]->song);
    sfMusic_play(game->proj[index]->song);
    shoot_bubble(game, index);
}
