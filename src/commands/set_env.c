/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** set.env
*/
#include <struct.h>
#include <tools.h>
#include <command.h>

int doesitexist(char **env, char *var)
{
    int lenvar = my_strlen(var) + 1;
    char *varcpy = malloc(sizeof(char) * (lenvar + 1));

    my_strcpy(varcpy, var);
    my_strcat(varcpy, "=");
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], varcpy, lenvar) == 0) {
            free(varcpy);
            return i;
        }
    }
    free(varcpy);
    return (-1);
}

void set_line(all_t *bools, char *var, char *info, int index)
{
    int i = 0;

    bools->env[index] = malloc(sizeof(char) *
    (my_strlen(var) + my_strlen(info) + 2));
    for (; var[i] != '\0'; i++)
        bools->env[index][i] = var[i];
    bools->env[index][i] = '=';
    i++;
    for (int j = 0; info[j] != '\0'; j++) {
        bools->env[index][i] = info[j];
        i++;
    }
    bools->env[index][i] = '\0';
}

void set_all_env(all_t *bools, char *var, char *info)
{
    int lenenv = 0;
    int i = 0;
    char **envcpy = my_strdup_array(bools->env);

    for (; envcpy[lenenv] != NULL; lenenv++);
    free_env(bools->env);
    bools->env = malloc(sizeof(char *) * (lenenv + 2));
    for (; envcpy[i] != NULL; i++) {
        bools->env[i] = my_strdup(envcpy[i]);
    }
    set_line(bools, var, info, i);
    bools->env[i + 1] = NULL;
}

void set_line_env(all_t *bools, char *var, char *info)
{
    free(bools->env[bools->indexvar]);
    set_line(bools, var, info, bools->indexvar);
}

static int good_arguments(all_t *bools, char *varenv, char *infoenv)
{
    if (varenv[0] <= '9' && varenv[0] >= '1') {
        mini_printf("setenv: Variable name must begin with a letter.\n");
        return (0);
    }
    for (int i = 1; varenv[i] != '\0'; i++) {
        if (varenv[i] >= 'a' && varenv[i] <= 'z') {
            continue;
        }
        if (varenv[i] >= 'A' && varenv[i] <= 'Z') {
            continue;
        }
        if (varenv[i] >= '1' && varenv[i] <= '9') {
            continue;
        }
        mini_printf("setenv: Variable name must "
        "contain alphanumeric characters.\n");
        bools->status = 1;
        return (0);
    }
    return (1);
}

int set_env(all_t *bools, char *varenv, char *infoenv)
{
    if (good_arguments(bools, varenv, infoenv) == 0)
        return (0);
    bools->indexvar = doesitexist(bools->env, varenv);
    if (bools->indexvar == -1) {
        set_all_env(bools, varenv, infoenv);
    } else {
        set_line_env(bools, varenv, infoenv);
    }
    return (1);
}
