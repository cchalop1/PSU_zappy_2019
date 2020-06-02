##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##


all: server

server:
		make -C server

clean:
		make -C server clean

fclean: clean
		make -C server fclean


re: fclean all

.PHONY: all clean fclean re server
