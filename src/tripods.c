/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** tripods
*/

#include "my_rpg.h"
#include <math.h>

game_object_t *create_pods(sfVector2f pos, sfIntRect rect, game_t *game)
{
    game_object_t *pods = create_game_object(game->assets_texture,
        pos, rect, SCALE(2));

    pods->type = PODS;
    sfSprite_setOrigin(pods->sprite, (sfVector2f)
        {pods->rect.width / 2, pods->rect.height / 2});
    pods->state = 0;
    return pods;
}

static float calc_cercle_point(float x, float r)
{
    return sqrt(pow(r, 2) - pow(x, 2));
}

static void draw_pods_particule(game_object_t *pods, game_t *game)
{
    float r = 50;
    static float progress = 0;
    float shift = 1;
    float x = -50 + progress;
    sfVector2i point_a = {x + pods->position.x,
    calc_cercle_point(x, r) + pods->position.y};
    sfVector2i point_b = {-x + pods->position.x,
    -calc_cercle_point(-x, r)+ pods->position.y};

    if (progress == 2 * r)
        progress = 0;
    draw_line(game->framebuffer, point_a, point_b,
    (sfUint8[4]) {0, 255, 255, 200});
    progress += shift;
}

void update_pods(game_object_t *pods, game_t *game)
{
    if (pods->state == PODS_TAKEN)
        pods->is_disabled = 1;
    if (pods->is_disabled)
        return;
    sfSprite_setPosition(pods->sprite, pods->position);
    sfRenderWindow_drawSprite(game->window, pods->sprite, NULL);
    if (get_time_clock(game->clock[PODS_C]) > 0.01) {
        draw_pods_particule(pods, game);
        sfClock_restart(game->clock[PODS_C]);
    }
    if (test_colliding(sfSprite_getGlobalBounds(pods->sprite),
        sfSprite_getGlobalBounds(PLAYER_FROM_GAME->sprite))) {
            pods->state = PODS_TAKEN;
            game->pods_collected++;
            update_quest(CURRENT_SCENE, game->pods_collected);
    }
}
