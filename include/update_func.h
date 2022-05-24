/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** update_func
*/

#pragma once

#include "my_rpg.h"

typedef void (*update_func_t)(game_object_t *obj, game_t *game);

const update_func_t UPDATE[13] = {&update_default,
                                &update_collision,
                                &update_item,
                                &update_pods,
                                &update_cage,
                                &update_enemies,
                                &update_player,
                                &update_parallax,
                                &update_parallax,
                                &update_parallax,
                                &update_parallax,
                                &update_wash,
                                &update_default};
