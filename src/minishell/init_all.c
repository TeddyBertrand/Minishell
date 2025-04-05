/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** init_all
*/
#include "struct.h"
#include <tools.h>

char *getfirstpath_parser(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return (env[i] + 5);
        }
    }
}

void init_all(all_t *bools, char **env)
{
    bools->exit = false;
    bools->env = my_strdup_array(env);
    bools->pwd = NULL;
    bools->oldpwd = NULL;
    bools->indexpassed = 0;
    bools->alcool = my_strdup("");
    bools->path = getfirstpath_parser(env);
}
