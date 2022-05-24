/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** hub
*/

#include "my_rpg.h"

static int get_nb_objects(scene_t *scene)
{
    int sum = scene->nb_tabs;

    for (int i = 0; i < scene->nb_tabs; i++) {
        sum += scene->tab[i]->nb_enemies;
        sum += scene->tab[i]->op_left ? 2 : 1;
        sum += scene->tab[i]->op_right ? 2 : 1;
        sum += scene->tab[i]->op_up ? 2 : 1;
        sum += scene->tab[i]->op_down ? 2 : 1;
    }
    sum += 8;
    return sum;
}

static void set_object(scene_t *scene, int i, game_t *game)
{
    static int index = 0;

    scene->objects[index] = create_game_object(game->assets_texture,
    V_TAB(GET_TAB(i, pos.x), GET_TAB(i, pos.y)), GET_TAB(i, rect), SCALE(4));
    index++;
    index += set_walls_left(scene, i, index, game);
    index += set_walls_right(scene, i, index, game);
    index += set_walls_up(scene, i, index, game);
    index += set_walls_down(scene, i, index, game);
    index += create_enemy(scene, i, index, game);
}

static void create_hub_button(game_t *game, scene_t *scene)
{
    scene->buttons = malloc(sizeof(button_t) * 4);
    scene->buttons[0] = create_quest_button(game->font);
    scene->buttons[1] = create_button((sfVector2f) {WIDTH - 250,
    HEIGHT - 220}, &player_competences_bubble, create_rect(290, 0, 35, 45),
    create_text(" ", game->font, NULL, 1));
    set_secondary_sprite(scene->buttons[1], create_rect(325, 0, 40, 40));
    set_tertiary_sprite(scene->buttons[1], create_rect(325, 40, 80, 15));
    sfSprite_setPosition(scene->buttons[1]->sec_sprite, (sfVector2f)
    {WIDTH - 250, HEIGHT - 100});
    scene->buttons[2] = create_button((sfVector2f) {WIDTH - 100,
    HEIGHT - 220}, &player_competences_cac, create_rect(290, 0, 35, 45),
    create_text(" ", game->font, NULL, 1));
    set_secondary_sprite(scene->buttons[2], create_rect(364, 0, 40, 40));
    set_tertiary_sprite(scene->buttons[2], create_rect(325, 40, 80, 15));
    sfSprite_setPosition(scene->buttons[2]->sec_sprite, (sfVector2f)
    {WIDTH - 100, HEIGHT - 100});
    scene->buttons[3] = NULL;
}

static void create_pods_in_scene(scene_t* scene, game_t* game)
{
    scene->objects[scene->nb_obj - 3] = create_pods(V_TAB(-4.5, 2.5),
    (sfIntRect) {1081, 225, 40, 34}, game);
    scene->objects[scene->nb_obj - 2] = create_pods(V_TAB(0.5, -5.5),
    (sfIntRect) {1121, 225, 40, 34}, game);
    scene->objects[scene->nb_obj - 1] = create_pods(V_TAB(10.5, 3.5),
    (sfIntRect) {1161, 225, 40, 34}, game);
}

scene_t *create_hub_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    init_scenes(scene, game);
    if (game->is_invalid)
        return NULL;
    scene->nb_obj = get_nb_objects(scene);
    create_hub_button(game, scene);
    scene->objects = malloc(sizeof(game_object_t) * (scene->nb_obj + 2));
    for (int i = 0; i < scene->nb_tabs; i++)
        set_object(scene, i, game);
    create_item(scene, 0, scene->nb_obj - 8, game);
    scene->objects[scene->nb_obj - 4] = create_cage(game);
    create_pods_in_scene(scene, game);
    scene->objects[scene->nb_obj] = create_player(game);
    scene->objects[scene->nb_obj + 1] = NULL;
    sort_object(scene->objects);
    scene->music = sfMusic_createFromFile("ressources/Courage under fire.ogg");
    sfMusic_setLoop(scene->music, sfTrue);
    return scene;
}
