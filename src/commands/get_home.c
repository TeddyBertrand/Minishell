/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** get_home
*/
#include <struct.h>
#include <tools.h>

char *get_home_parser(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            return (env[i] + 5);
        }
    }
    return NULL;
}
