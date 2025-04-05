/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** unset_env
*/
#include <struct.h>
#include <tools.h>
#include <command.h>


void unset_all_env(all_t *bools)
{
    int lenenv = 0;
    int i = 0;
    char **envcpy = my_strdup_array(bools->env);

    for (; envcpy[lenenv] != NULL; lenenv++);
    free_env(bools->env);
    bools->env = malloc(sizeof(char *) * (lenenv));
    for (; i != bools->indexvar; i++)
        bools->env[i] = my_strdup(envcpy[i + bools->indexpassed]);
    bools->indexpassed = 1;
    for (; envcpy[i + bools->indexpassed] != NULL; i++)
        bools->env[i] = my_strdup(envcpy[i + bools->indexpassed]);
    bools->env[i] = NULL;
}

int unset_env(all_t *bools, char *varenv)
{
    bools->indexvar = doesitexist(bools->env, varenv);
    if (bools->indexvar == -1) {
        return (0);
    } else {
        unset_all_env(bools);
        bools->indexpassed = 0;
    }
    return (0);
}
