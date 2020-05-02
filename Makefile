##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	main.c \
		button_obj_is_hover.c \
		game_menu/game.c \
		game_menu/tile_mapping.c \
		game_menu/display_map_core.c \
		game_menu/free_game_res.c \
		game_menu/camera_fight_zoom.c \
		game_menu/display_optimizer.c \
		start_menu/start.c \
		start_menu/init_start.c \
		start_menu/buttons_actions.c \
		start_menu/buttons_hover.c \
		pause_menu/pause.c \
		pause_menu/pause_button.c \
		settings_menu/settings.c \
		settings_menu/buttons_actions.c \
		settings_menu/init_settings.c \
		howtoplay_menu/how_to_play.c \
		fight_system/fight_core.c \
		player/player_core.c\
		player/init_destroy.c \
		player/player_collision.c \
		choose_skin/choose_skin.c \
		choose_skin/event_skin.c \
		inventory/initialize_inventory.c \
		inventory/set_items.c \
		inventory/free_inventory.c	\
		inventory/display_inventory.c

NAME	=		my_rpg

OBJ		=		$(SRC:.c=.o)

CFLAGS		+=	-Wextra -W -pedantic -I./include

LDFLAGS		=	-L./lib/my -lmy

CSFMLF		=	-l csfml-audio -l csfml-system -l csfml-graphics -l csfml-window

MAKE_LIB	=	make -C ./lib/my/

DEMAKE_LIB	=	make -C ./lib/my/ fclean

all:	$(OBJ)
		$(MAKE_LIB)
		gcc $(OBJ) -o $(NAME) $(LDFLAGS) $(CSFMLF) -g3

clean:
		$(DEMAKE_LIB)
		rm -f $(OBJ)
		rm -f *~
		rm -f *\#
		rm -f *.o

fclean:	clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: clean, fclean, re, all