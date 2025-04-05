/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** env
*/
#include <tools.h>

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        mini_printf("%s\n", env[i]);
}
