##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	main.c \
		game_menu/game.c \
		start_menu/start.c \
		start_menu/init_start.c \
		pause_menu/pause.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	NAME

NAME:
	cd lib/my/ && make
	gcc $(SRC) -o $(NAME) -l csfml-graphics -l csfml-audio -l csfml-system -L ./lib/my -lmy

clean:
	rm -f $(OBJ)
	cd lib/my/ && rm *.o

fclean: clean
	rm $(NAME)

re : fclean all
