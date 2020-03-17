##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	main.c \
		destroy/destroy.c \
		initialization/main_initialize.c \
		display/main_display.c

OBJ	=	$(SRC:.c=.o)

NAME	=	a.out

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
