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
		game_menu/fight_management.c \
		game_menu/fight_camera_zoom.c \
		game_menu/draw_entity.c \
		game_menu/initialize_game.c \
		game_menu/message_management.c \
		game_menu/game_event.c \
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
		fight_system/fight_init_core.c \
		fight_system/fight_destroy.c \
		fight_system/display_infos_areas.c \
		fight_system/turn_core.c \
		fight_system/fight_init_areas.c \
		fight_system/fight_attack_animation.c \
		fight_system/fight_buttons_effects.c \
		fight_system/fight_end.c \
		player/player_core.c\
		player/player_view.c\
		player/init_destroy.c \
		player/player_collision.c \
		player/player_animation.c \
		player/player_gps.c \
		choose_skin/choose_skin.c \
		choose_skin/event_skin.c \
		inventory/initialize_inventory.c \
		inventory/set_items.c \
		inventory/free_inventory.c	\
		inventory/display_inventory.c \
		npc/action_move_npc.c \
		npc/action_wait_npc.c \
		npc/action_focus_npc.c \
		npc/manage_npc_actions.c \
		message_box/action_message.c \
		message_box/init_message_box.c \
		message_box/display_message_box.c \
		npc/initialize_npc.c \
		npc/collision.c \
		inventory/stat/stat_player.c \
		inventory/stat/free_stats.c

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