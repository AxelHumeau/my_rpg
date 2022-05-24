/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** make player animation
*/

#include "my_rpg.h"

static int animation_p(game_t *game, int nb_anim_s, float time_s, int top_s)
{
    PLAYER_FROM_GAME->rect.top = top_s;
    PLAYER_FROM_GAME->rect.left += PLAYER_FROM_GAME->rect.width + 19;
    if (PLAYER_FROM_GAME->rect.left >
        (420 + ((PLAYER_FROM_GAME->rect.width + 29) * (nb_anim_s - 1)))) {
        PLAYER_FROM_GAME->idle = true;
        return (0);
    }
    PLAYER_FROM_GAME->saved_anim =
    get_time_clock(game->clock[PLAYER_C]);
    return (1);
}

void make_player_anim(game_t *game, int nb_anim, float time, int top)
{
    static int first = 0;
    static int nb_anim_s = 0;
    static float time_s = 0;
    static int top_s = 0;

    if (!first) {
        first = 1;
        nb_anim_s = nb_anim;
        time_s = time;
        top_s = top;
    }
    if (get_time_clock(game->clock[PLAYER_C]) - PLAYER_FROM_GAME->saved_anim >
        time_s) {
        first = animation_p(game, nb_anim_s, time_s, top_s);
    }
}
