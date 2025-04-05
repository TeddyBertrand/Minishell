/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** get_oldpwd
*/
#include <tools.h>

char *get_oldpwd_parser(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "OLDPWD=", 7) == 0) {
            return (env[i] + 7);
        }
    }
    return NULL;
}
