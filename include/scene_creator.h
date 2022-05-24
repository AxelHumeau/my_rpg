/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** scene_creator
*/

#pragma once

#include "my_rpg.h"

scene_creator_t const SCENES_CREATOR[NB_SCENES] = {&create_menu_scene,
                                                    &create_hub_scene,
                                                    &create_game_over_scene,
                                                    &create_credit_scene};
