##
## EPITECH PROJECT, 2022
## My RPG
## File description:
## Makefile
##

DIR = src/

SRC =	$(DIR)button/callback.c				\
		$(DIR)button/update.c				\
		$(DIR)button/button.c				\
		$(DIR)create/vector.c				\
		$(DIR)create/window.c				\
		$(DIR)create/enemy.c				\
		$(DIR)create/mana_and_xp_bar.c		\
		$(DIR)base_game/loop.c				\
		$(DIR)base_game/object.c			\
		$(DIR)base_game/game.c				\
		$(DIR)base_game/collision.c			\
		$(DIR)base_game/wall.c				\
		$(DIR)base_game/set_wall.c			\
		$(DIR)base_game/game_over.c			\
		$(DIR)base_game/competences.c		\
		$(DIR)init/init.c					\
		$(DIR)init/init_projectile.c		\
		$(DIR)init/init_inventory.c			\
		$(DIR)init/init_controls.c			\
		$(DIR)init/init_scenes.c			\
		$(DIR)init/init_enemy.c				\
		$(DIR)init/sort_object.c			\
		$(DIR)init/init_texture.c			\
		$(DIR)read_config/config_scene_func.c\
		$(DIR)read_config/read_config_file.c\
		$(DIR)item/item.c					\
		$(DIR)item/get_item.c				\
		$(DIR)projectil/basic.c				\
		$(DIR)projectil/projectile_handle.c	\
		$(DIR)inventory/create_inventory.c	\
		$(DIR)inventory/inventory_handle.c	\
		$(DIR)menu/start_menu.c				\
		$(DIR)menu/pause.c					\
		$(DIR)menu/settings.c				\
		$(DIR)menu/create_settings_menu.c	\
		$(DIR)credits/credit.c				\
		$(DIR)credits/parallax.c			\
		$(DIR)credits/washing_machine.c		\
		$(DIR)particules/parts.c			\
		$(DIR)particules/framebuffer.c		\
		$(DIR)particules/draw_lines.c		\
		$(DIR)enemies/update.c				\
		$(DIR)enemies/attack_pattern.c		\
		$(DIR)enemies/animation.c			\
		$(DIR)enemies/is_player_near.c		\
		$(DIR)enemies/idle.c				\
		$(DIR)enemies/place_random_enemies.c\
		$(DIR)enemies/get_first_enemy_index.c\
		$(DIR)player/update.c				\
		$(DIR)player/create.c				\
		$(DIR)player/walk.c					\
		$(DIR)player/animation.c			\
		$(DIR)player/melee_player.c			\
		$(DIR)player/draw_enemy_on_top.c	\
		$(DIR)get_ratio_difficulty.c		\
		$(DIR)hub.c							\
		$(DIR)update_bar.c					\
		$(DIR)mouse.c						\
		$(DIR)scene.c						\
		$(DIR)text.c						\
		$(DIR)clocks.c						\
		$(DIR)read_line.c					\
		$(DIR)my_atof.c						\
		$(DIR)camera.c						\
		$(DIR)disable_non_near_objects.c	\
		$(DIR)quest.c						\
		$(DIR)tripods.c						\
		$(DIR)cage.c						\

OBJ =	$(SRC:.c=.o)

MAIN =	$(DIR)main.c

OBJ_MAIN =	$(MAIN:.c=.o)

CC =	gcc

CFLAGS =	-Wall

CPPFLAGS =	-I ./include

LDFLAGS =	-Llib -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio	\
			-lcsfml-window -lm

NAME =	my_rpg

RESSOURCES =	asset

UNCOMPRESS_RES = ressources

all: $(NAME)

zip:
	rm -f $(RESSOURCES).zip
	zip $(RESSOURCES).zip ressources/*

$(UNCOMPRESS_RES):
	unzip $(RESSOURCES).zip

$(NAME): $(OBJ) $(OBJ_MAIN) $(UNCOMPRESS_RES)
	make -C ./lib/my/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(OBJ_MAIN)

fclean: clean
	rm -f $(NAME)
	rm -rf ressources

debug:	CFLAGS += -g
debug:	fclean all

re: fclean all

.PHONY :	all re clean fclean debug
