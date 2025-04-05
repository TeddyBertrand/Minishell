/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-minishell1-alban.lembrez
** File description:
** my_strup.c
*/

#include "tools.h"

char *my_strdup(char *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; str[i] != '\0'; i++) {
        result[i] = str[i];
    }
    result[my_strlen(str)] = '\0';
    return result;
}
