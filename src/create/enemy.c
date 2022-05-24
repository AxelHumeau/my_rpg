/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_enemy
*/

#include "my_rpg.h"

static int struct_length(enemies_info_t **nmi_inf)
{
    int len = 0;

    for (; nmi_inf[len]; len++);
    return len;
}

static void add_specificities2(game_object_t *object, info_tab_t *tab,
game_t *game, enemies_info_t *nmi_inf)
{
    object->saved_anim = 0;
    object->saved_atk = 0;
    object->saved_idle = 0;
    object->triggered = false;
    object->state = 0;
    sfSprite_setOrigin(object->sprite, (sfVector2f)
    {nmi_inf->rect.height / 2, nmi_inf->rect.width / 2});
    object->cac = nmi_inf->cac;
    object->xp = get_res_with_diff(nmi_inf->xp, tab->difficulty, 30);
}

static void add_specificities(game_object_t *object, info_tab_t *tab,
game_t *game, enemies_info_t *nmi_inf)
{
    object->type = ENEMY;
    object->hp = get_res_with_diff(nmi_inf->health, tab->difficulty, 100);
    create_hp_bar(object, 0);
    object->animation = nmi_inf->animation;
    object->clock = sfClock_create();
    sfSprite_setScale(object->sprite, nmi_inf->size);
    object->damage = get_res_with_diff(nmi_inf->damage, tab->difficulty, 60);
    object->animation_speed = 0.2;
    object->attk_speed = get_res_with_diff(nmi_inf->attack_speed,
    tab->difficulty, 15);
    object->attk_speed = object->attk_speed + (((float) rand() / (float)
    RAND_MAX) * (object->attk_speed * 15 / 100));
    object->reach = get_res_with_diff(nmi_inf->reach, tab->difficulty, 10);
    object->idle = true;
    object->normalize = (sfVector2f) {0, 0};
    object->speed = (sfVector2f) {get_res_with_diff(nmi_inf->speed.x,
    tab->difficulty, 1), get_res_with_diff(nmi_inf->speed.y,
    tab->difficulty, 1)};
    add_specificities2(object, tab, game, nmi_inf);
}

static int get_random_enemy(game_t *game, int random, int type)
{
    int save = -1;
    int nb = 0;

    for (int i = 0; game->nmi_inf[i]; i++) {
        if (game->nmi_inf[i]->cac == type)
            nb++;
        if (nb == 1 && save == -1)
            save = i;
    }
    if (nb == 0)
        return (0);
    if (struct_length(game->nmi_inf) != 1)
        random = (save + rand() % nb);
    else
        random = 0;
    if (random == struct_length(game->nmi_inf))
        random -= 1;
    return (random);
}

int create_enemy(scene_t *scene, int i, int index, game_t *game)
{
    int random;

    if (scene->tab[i]->nb_enemies == 0)
        return (0);
    for (int j = 0; j < scene->tab[i]->nb_enemies; j++, index++) {
        random = get_random_enemy(game, random,
        scene->tab[i]->type_enemies[j]);
        scene->objects[index] = create_game_object(
        game->assets_texture, random_place(scene, i),
        game->nmi_inf[random]->rect, game->nmi_inf[random]->size);
        add_specificities(scene->objects[index], scene->tab[i], game,
        game->nmi_inf[random]);
    }
    return (scene->tab[i]->nb_enemies);
}
