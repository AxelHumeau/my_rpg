/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include "my_rpg.h"

static void stat_projectil(game_t *game, int i)
{
    game->proj[i]->is_shooting = false;
    game->proj[i]->shoot = false;
    game->proj[i]->speed = create_vector(10, 10);
    game->proj[i]->target.x = 0;
    game->proj[i]->target.y = 0;
    game->proj[i]->position = create_vector(WIDTH / 2, HEIGHT / 2);
    game->proj[i]->rect = create_rect(175, 2272, 76, 74);
    game->proj[i]->move_v = create_vector(0, 0);
    game->proj[i]->target_distance = create_vector(0, 0);
    game->proj[i]->clock = sfClock_create();
    game->proj[i]->damage = 10;
    game->proj[i]->animation = 27;
    game->proj[i]->splash =
    init_texture_sprite(game->assets_texture);
    game->proj[i]->splashing = false;
    game->proj[i]->splash_rect = create_rect(131, 2439, 33, 33);
    sfSprite_setTextureRect(game->proj[i]->sprite, game->proj[i]->rect);
    sfSprite_setTextureRect(game->proj[i]->splash, game->proj[i]->splash_rect);
    sfSprite_setScale(game->proj[i]->splash, SCALE(2.4));
    game->proj[i]->auto_target = false;
}

void init_projectile(game_t *game)
{
    for (int i = 0; i < PROJ_NB; i++) {
        game->proj[i] = malloc(sizeof(projectile_t));
        game->proj[i]->sprite = init_texture_sprite(game->assets_texture);
        stat_projectil(game, i);
        game->proj[i]->is_enemy = false;
        sfSprite_setOrigin(game->proj[i]->sprite, (sfVector2f) {39, 37});
        sfSprite_setOrigin(game->proj[i]->splash, (sfVector2f) {16, 16});
        sfSprite_setScale(game->proj[i]->sprite, SCALE(0.5));
        game->proj[i]->song = sfMusic_createFromFile(
        "ressources/bubble song.ogg");
    }
    game->proj[PROJ_NB] = NULL;
    game->index = 0;
}
