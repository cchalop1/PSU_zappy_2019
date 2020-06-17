/*
** EPITECH PROJECT, 2019
** str_to_a
** File description:
** transform string to array
*/

#include <stdlib.h>
#include <stdbool.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return i;
}

int my_tablen(char **arr)
{
    int i = 0;

    while (arr[i] != NULL)
        i = i + 1;
    return i;
}

char **array_alloc(char *str)
{
    int count = 0;
    char **arr = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            count = count + 1;
    }
    arr = malloc(sizeof(char *) * (count + 1));
    return arr;
}

char *my_strcpy(char *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src));

    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return dest;
}

char **str_to_array(char *str)
{
    char **arr = array_alloc(str);
    int x = 0;
    int y = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(str));

    for (int i = 0; str[i] != '\0' && str[i] != '\n' && str[i] != '\r'; i++) {
        if (str[i] == ' ') {
            tmp[y] = '\0';
            arr[x] = my_strcpy(tmp);
            x = x + 1;
            y = 0;
            tmp = malloc(sizeof(char) * my_strlen(str));
        }
        else {
            tmp[y] = str[i];
            y = y + 1;
        }
    }
    arr[x] = my_strcpy(tmp);
    return arr;
}