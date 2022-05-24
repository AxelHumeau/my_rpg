/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game
*/

#include "my_rpg.h"

static void create_game_button(game_t *game)
{
    game->pause_button = create_button(ORIGIN_V, &pause_b, SMALL_B,
    create_text(" ", game->font, NULL, 30));
    set_secondary_sprite(game->pause_button, create_rect(213, 0, 43, 45));
    game->resume_button = create_button(create_vector((WIDTH - 340) / 2,
        HEIGHT / 3), &resume, STANDARD_B, create_text("RESUME",
        game->font, NULL, 30));
    game->menu_button = create_button(create_vector((WIDTH - 340) / 2,
        HEIGHT / 6 * 3), &return_to_menu, STANDARD_B,
        create_text("MENU", game->font, NULL, 30));
    game->quit_button = create_button(create_vector((WIDTH - 340) / 2,
        HEIGHT / 6 * 4), &quit_game, STANDARD_B,
        create_text("QUIT", game->font, NULL, 30));
}

static void create_sound_effects(game_t *game)
{
    sfMusic **sound_effects = malloc(sizeof(sfMusic *) * 6);

    sound_effects[0] = sfMusic_createFromFile("ressources/Explosion.ogg");
    sound_effects[1] = sfMusic_createFromFile("ressources/hurt.ogg");
    sound_effects[2] = sfMusic_createFromFile("ressources/splash.ogg");
    sound_effects[3] = sfMusic_createFromFile("ressources/washed.ogg");
    sound_effects[4] = sfMusic_createFromFile("ressources/lvl up.ogg");
    sound_effects[5] = NULL;
    game->sound_effects = sound_effects;
    game->volume = 100;
}

static game_object_t *create_and_display_loading_screen(game_t *game)
{
    game_object_t *loading_screen = create_game_object(game->assets_texture,
    ORIGIN_V, (sfIntRect) {0, 512, 400, 225}, SCALE(4));

    game->window = create_window("WoW", WIDTH, HEIGHT);
    sfRenderWindow_drawSprite(game->window, loading_screen->sprite, NULL);
    sfRenderWindow_display(game->window);
    game->is_invalid = false;
    game->pods_collected = 0;
    return loading_screen;
}

game_t *create_game(char *player_name)
{
    game_t *game = malloc(sizeof(game_t));
    game_object_t *loading_screen;

    init_texture(game);
    loading_screen = create_and_display_loading_screen(game);
    init_all(game);
    if (game->is_invalid)
        return (game);
    game->clock = create_clocks();
    game->font = sfFont_createFromFile("ressources/SuperLegendBoy-4w8Y.ttf");
    game->is_invalid = false;
    game->scenes = create_scenes(game);
    game->current_scene = 0;
    game->is_paused = 0;
    create_game_button(game);
    create_sound_effects(game);
    game->framebuffer = create_framebuffer(WIDTH, HEIGHT);
    game->is_camera_moving = false;
    destroy_game_object(loading_screen);
    return (game);
}

void destroy_game(game_t *game)
{
    destroy_textures(game);
    sfRenderWindow_destroy(game->window);
    destroy_all_scenes(game->scenes);
    destroy_button(game->pause_button);
    destroy_button(game->resume_button);
    destroy_button(game->menu_button);
    destroy_button(game->quit_button);
    sfFont_destroy(game->font);
    destroy_clocks(game->clock);
    destroy_framebuffer(game->framebuffer);
    for (int i = 0; game->sound_effects[i] != NULL; i++)
        sfMusic_destroy(game->sound_effects[i]);
    for (int i = 0; i < PROJ_NB; i++) {
        sfMusic_stop(game->proj[i]->song);
        sfMusic_destroy(game->proj[i]->song);
    }
    free(game->sound_effects);
    free(game);
}
