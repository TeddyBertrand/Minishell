/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** my_commands
*/
#include <struct.h>
#include <main.h>
#include <tools.h>
#include <command.h>

int my_commandes_bonus(all_t *bools, char **commande)
{
    if (my_strcmp(commande[0], "echo") == 0) {
        if (commande[1] != NULL && my_strcmp(commande[1], "$?") == 0) {
            mini_printf("%d\n", bools->status);
            return (0);
        }
    }
    if (my_strcmp(commande[0], "squeezie") == 0) {
        mini_printf("Yop tout le monde c'est Squeezie !\n C'est ciao\n");
        bools->exit = true;
        return (0);
    }
    if (my_strcmp(commande[0], "antoine") == 0) {
        bools->alcool = my_strdup("     _]=[_\n   .-'(P)'-.\n   |absolut|\n"
        "   | ~~~~~ |\n   | ~~~~~ |\n"
        "   | ~~~~~ |\n   '_______'\n            ");
        return (0);
    }
    return (1);
}

int my_commande_unsetenv(all_t *bools, char **commande)
{
    if (my_strcmp(commande[0], "unsetenv") == 0) {
        if (commande[1] == NULL) {
            mini_printf("unsetenv: Too few arguments.\n");
            bools->status = 1;
            return (0);
        }
        for (int i = 0; commande[i] != NULL; i++)
            unset_env(bools, commande[i]);
        return (0);
    }
    return (1);
}

int my_commande_setenv(all_t *bools, char **commande)
{
    if (my_strcmp(commande[0], "setenv") == 0) {
        if (commande[1] == NULL) {
            print_env(bools->env);
            return (0);
        }
        if (commande[2] == NULL) {
            set_env(bools, commande[1], "");
            return (0);
        }
        if (commande[3] != NULL) {
            mini_printf("setenv: Too many arguments.\n");
            bools->status = 1;
            return (0);
        }
        set_env(bools, commande[1], commande[2]);
        return (0);
    }
    return (1);
}

int my_commands_env(all_t *bools, char **commande)
{
    if (my_strcmp(commande[0], "env") == 0) {
        if (commande[1] != NULL) {
            bools->status = 1;
            mini_printf("env: Too many arguments.\n");
            return (0);
        }
        print_env(bools->env);
        return (0);
    }
    if (my_commande_setenv(bools, commande) == 0)
    return (0);
    if (my_commande_unsetenv(bools, commande) == 0)
    return (0);
    if (my_commandes_bonus(bools, commande) == 0)
    return (0);
    return (1);
}

static int my_commands_cd(all_t *bools, char **commande)
{
    char *HOME;

    if (my_strcmp(commande[0], "cd") == 0 ||
    my_strcmp(commande[0], "chdir") == 0) {
        if (commande[1] == NULL) {
            HOME = get_home_parser(bools->env);
            chdir(HOME);
            return (0);
        }
        if (commande[2] != NULL) {
            mini_printf("cd: Too many arguments.\n");
            bools->status = 1;
            return (0);
        }
        commande_cd(commande, bools);
        return (0);
    }
    return (1);
}

int my_commands(char **commande, all_t *bools)
{
    if (commande[0] == NULL)
        return (0);
    if (my_strcmp(commande[0], "exit") == 0) {
        my_exit(bools, commande);
        return (0);
    }
    if (my_commands_cd(bools, commande) == 0)
        return (0);
    if (my_commands_env(bools, commande) == 0)
        return (0);
    return (1);
}
