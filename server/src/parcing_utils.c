/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** parcing_utils
*/

#include "server.h"

// TODO: norme ?
static int count_space(const char* raw_str)
{
    char str[BUFFER_SIZE];
    int nb_words = 0;
    char delim[] = " ";
    strcpy(str, raw_str);
    char* ptr = strtok(str, delim);

    for (; ptr != NULL; ptr = strtok(NULL, delim))
        nb_words++;
    return nb_words;
}

// TODO: norme ?
char** parse_string_delim(const char* raw_str, const char* delim_raw)
{
    char str[BUFFER_SIZE];
    char delim[4];
    int nb_words = count_space(raw_str);
    char** arr = NULL;
    int i = 0;
    char* ptr;

    strcpy(str, raw_str);
    strcpy(delim, delim_raw);
    ptr = strtok(str, delim);
    arr = malloc(sizeof(char*) * (nb_words + 1));
    for (; ptr != NULL; ptr = strtok(NULL, delim), i++)
        arr[i] = strdup(ptr);
    arr[i] = NULL;
    return arr;
}