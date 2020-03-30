##
## EPITECH PROJECT, 2018
## my_printf
## File description:
## Makefile
##

SRC	=	initialize_window.c \
		make_sprite.c \
		make_texture.c \
		make_text.c \
		button_is_clicked.c \
		my_getstr.c \
		my_revstr.c \
		my_strcat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	NAME

NAME:
	gcc -c $(SRC) -l csfml-graphics -l csfml-audio -l csfml-system
	ar rc $(NAME) $(OBJ) $(OBJ_FOLDER)
	rm *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all