/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player competences
*/

#include "my_rpg.h"

void player_competences_bubble(game_t *game, button_t *button)
{
    if (button->ter_rect.width >= 75)
        return;
    button->ter_rect.width += 15;
    sfSprite_setTextureRect(button->auxiliary_sprite, button->ter_rect);
    PLAYER_FROM_GAME->mage_dmg += 6;
    PLAYER_FROM_GAME->mage_speed -= 0.17;
    if (button->ter_rect.width > 30)
        PLAYER_FROM_GAME->mana_recovery += 1;
    PLAYER_FROM_GAME->xp = 0;
    sfMusic_stop(game->sound_effects[4]);
    sfMusic_play(game->sound_effects[4]);
}

void player_competences_cac(game_t *game, button_t *button)
{
    if (button->ter_rect.width >= 75)
        return;
    button->ter_rect.width += 15;
    sfSprite_setTextureRect(button->auxiliary_sprite, button->ter_rect);
    PLAYER_FROM_GAME->damage += 9;
    PLAYER_FROM_GAME->attk_speed -= 0.1;
    PLAYER_FROM_GAME->reach += 2;
    if (button->ter_rect.width > 30) {
        PLAYER_FROM_GAME->speed.x += 1;
        PLAYER_FROM_GAME->speed.y += 1;
    }
    PLAYER_FROM_GAME->xp = 0;
    sfMusic_stop(game->sound_effects[4]);
    sfMusic_play(game->sound_effects[4]);
}
