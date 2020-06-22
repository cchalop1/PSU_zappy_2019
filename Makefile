##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##


all:  server
		cp ./client/zappy_ai ./zappy_ai
		chmod +x ./zappy_ai

server:
		make -C server

clean:
		make -C server clean

fclean: clean
		make -C server fclean
		@rm -f ./zappy_ai

client:


re: fclean all

.PHONY: all clean fclean re server
