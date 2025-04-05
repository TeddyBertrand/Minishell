/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** is_accessible
*/
#include <struct.h>
#include <includes.h>
#include <tools.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *getpath_parser(char **env, all_t *bools)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return (env[i] + 5);
        }
    }
    return (bools->path);
}

char *getpath(char *token, char *buff, char *commande)
{
        buff = malloc(sizeof(char) *
        (my_strlen(token) + my_strlen(commande) + 2));
        my_strcpy(buff, token);
        buff = my_strcat(buff, "/");
        buff = my_strcat(buff, commande);
        return buff;
}

char *is_accessible(all_t *bools, char *commande)
{
    char *pathfile = getpath_parser(bools->env, bools);
    char *path = my_strdup(pathfile);
    char *token = strtok(path, ":");
    char *buff;

    for (; token != NULL;) {
        buff = getpath(token, buff, commande);
        if (access(buff, F_OK) == 0) {
            free(path);
            return buff;
        }
        free(buff);
        token = strtok(NULL, ":");
    }
    free(path);
    return commande;
}
