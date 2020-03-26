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

NAME	=		my_rpg

OBJ		=		$(SRC:.c=.o)

CFLAGS		+=	-Wextra -W -pedantic -I./include 

LDFLAGS		=	-L./lib/my -lmy

CSFMLF		=	-l csfml-audio -l csfml-system -l csfml-graphics

MAKE_LIB	=	make -C ./lib/my/

DEMAKE_LIB	=	make -C ./lib/my/ fclean

all:	$(OBJ)
		$(MAKE_LIB)
		gcc $(OBJ) -o $(NAME) $(LDFLAGS) $(CSFMLF)

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