/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** First file for particules
*/

#include "my_rpg.h"
#include "particles.h"

int my_psegment(fbr_t *fbuffer, sfVector2i pa, int l, sfUint8 *clr)
{
    for (; pa.x != l; pa.x++) {
        my_ppixel(fbuffer, pa.x, pa.y, clr);
    }
    return 0;
}

int my_psquare(fbr_t *fbuffer, unsigned int x, unsigned int y, int size)
{
    sfUint8 *clr = cmaker(250, 205, 140);
    sfVector2i point_a;

    point_a.x = x;
    point_a.y = y;
    for (; point_a.y != y + size; point_a.y++)
        my_psegment(fbuffer, point_a, point_a.x + size, clr);
    return 0;
}

void fade(game_t *game)
{
    if (game->current_scene != HUB)
        return;
    if (get_time_clock(game->clock[FADE_C]) > 0.1) {
        for (int i = 0; i < game->framebuffer->width *
        game->framebuffer->height * 4; i += 4) {
            game->framebuffer->pixels[i + 3] -=
            game->framebuffer->pixels[i + 3] >= 50 ? 50 : 0;
        }
        sfClock_restart(game->clock[FADE_C]);
    }
}

void walk_particles(game_t *game, int dx, int dy)
{
    static float saved_clock;

    if (get_time_clock(game->clock[PLAYER_C]) - saved_clock > 0.2) {
        my_psquare(game->framebuffer, PLAYER_FROM_GAME->position.x - dx,
            PLAYER_FROM_GAME->position.y - dy - 12, rand() % 15);
        my_psquare(game->framebuffer, PLAYER_FROM_GAME->position.x - dx,
            PLAYER_FROM_GAME->position.y - dy + 12, rand() % 15);
        my_psquare(game->framebuffer, PLAYER_FROM_GAME->position.x - dx - 12,
            PLAYER_FROM_GAME->position.y - dy, rand() % 15);
        my_psquare(game->framebuffer, PLAYER_FROM_GAME->position.x - dx + 12,
            PLAYER_FROM_GAME->position.y - dy, rand() % 15);
        saved_clock = get_time_clock(game->clock[PLAYER_C]);
    }
}

void display_framebuffer(game_t *game)
{
    if (game->is_camera_moving || game->current_scene != HUB)
        return;
    fade(game);
    sfTexture_updateFromPixels(game->framebuffer->texture,
        game->framebuffer->pixels, WIDTH, HEIGHT, 0, 0);
    sfSprite_setTexture(game->framebuffer->sprite,
        game->framebuffer->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->framebuffer->sprite, NULL);
}
