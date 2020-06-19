##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for ZAPPY
##

SRC	=	src/main.cpp \
		src/Client.cpp	\
		src/Graphic_client.cpp	\
		src/Item.cpp	\
		src/Map.cpp

OBJ		=	$(SRC:.cpp=.o) \

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra

NAME = graphic_client

all: $(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf *~ *# vgcore* src/*~ src/*# include/*~ include/*#

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
