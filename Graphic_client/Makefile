##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for ZAPPY
##

SRC	=	src/main.c \
		src/init_client.c \

OBJ		=	$(SRC:.c=.o) \

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra


NAME = graphic_client

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -rf *~ *# vgcore* src/*~ src/*# include/*~ include/*#

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
