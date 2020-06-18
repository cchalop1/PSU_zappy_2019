/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init_client
*/

#include "../include/client.h"

t_client init_client(void)
{
    t_client new;
    new.fd = 0;
    new.username = NULL;
    new.password = NULL;
    return new;
}

char *init_uuid(void)
{
    char *new_uuid = malloc(sizeof(char) * 36);
    int rand_number = 0;

    srand(time(NULL));
    for (int i = 0; i != 36; i++)
    {
        rand_number = rand()%16;
        if (i == 8 || i == 13 || i == 18 || i == 23)
            new_uuid[i] = '-';
        else if (rand_number >= 10){
            new_uuid[i] = rand_number + 87;
        }
        else
            new_uuid[i] = rand_number + 48;
    }
    return new_uuid;
}

