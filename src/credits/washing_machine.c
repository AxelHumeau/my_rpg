/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** washing_machine
*/

#include "my_rpg.h"

static void shift_wash(game_object_t *washing_machine)
{
    washing_machine->rect.left += washing_machine->rect.width;
    if (washing_machine->rect.left > 1039) {
        washing_machine->rect.left = 885;
        washing_machine->rect.top += washing_machine->rect.height;
        if (washing_machine->rect.top > washing_machine->rect.height + 225)
            washing_machine->rect.top = 225;
    }
}

void update_wash(game_object_t *wm, game_t *game)
{
    if (wm->is_disabled)
        return;
    sfSprite_setTextureRect(wm->sprite,wm->rect);
    if (get_time_clock(game->clock[WASH_MACHINE_C]) > 1.0 / 30.0) {
        shift_wash(wm);
        wm->position.x += 2;
        CURRENT_SCENE->buttons[1]->pos.y -= 2.2;
        sfClock_restart(game->clock[WASH_MACHINE_C]);
    }
    sfSprite_setPosition(wm->sprite, wm->position);
    sfRenderWindow_drawSprite(game->window, wm->sprite, NULL);
    if (wm->position.x >= WIDTH)
        skip_ending(game, CURRENT_SCENE->buttons[0]);
}

game_object_t *create_washing_machine(game_t *game)
{
    game_object_t *washing_machine = create_game_object(game->assets_texture,
    create_vector(100, HEIGHT - 400), create_rect(885, 225, 31, 40), SCALE(7));

    washing_machine->type = WASH_MACHINE;
    washing_machine->is_disabled = 0;
    return (washing_machine);
}
