##
## EPITECH PROJECT, 2020
## PSU_zappy_2019
## File description:
## Makefile
##


SRC = 	$(wildcard ./src/*.c)

# LDFLAGS =

CC = gcc

CFLAGS = -W -Wextra -I./includes/ -g3

NAME = ../zappy_server

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
