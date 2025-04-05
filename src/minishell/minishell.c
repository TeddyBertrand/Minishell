/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** minishell
*/
#include "struct.h"
#include "tools.h"
#include "main.h"
#include <command.h>

int getline_error(ssize_t nread, all_t *bools)
{
    if (nread == -1) {
        exit(0);
    } else if (nread == 1) {
        return (0);
    }
    return (1);
}

void print_path(all_t *bools)
{
    char *str = getcwd(NULL, 0);

    if (isatty(0))
        if (bools->exit == 0)
        mini_printf("\033[1;32mteddy@teddy-Dell-G16-7630:"
        "\033[1;34m%s\033[0m$> ", str);
    free(str);
}

void execute_builtins_after(char *cmd, all_t *all)
{
    char **possible_builtin = my_str_to_word_array(cmd, " \t\n");

    my_commands(possible_builtin, all);
}

bool execute_current(char **main_branchs, int i, all_t *all)
{
    if (!no_more_separator(main_branchs[i], my_strlen(main_branchs[i]))) {
        all->binary = create_binary_tree(main_branchs[i]);
        if (all->binary == NULL)
            return false;
        execute_binary_tree(all->binary, all);
        execute_builtins_after(all->binary->right->data, all);
        } else {
        execute_unique(main_branchs[i], all);
        }
    return true;
}

int minishell(all_t *all)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int nb_separator = 0;
    char **main_branchs;

    print_path(all);
    nread = getline(&line, &len, stdin);
    if (getline_error(nread, all) == 0)
        return (all->status);
    main_branchs = my_str_to_word_array(line, ";");
    for (; main_branchs[nb_separator + 1] != NULL; nb_separator++);
    for (int i = 0; i <= nb_separator; i++) {
        if (!execute_current(main_branchs, i, all)) {
            my_putstr_error("Invalid null command.\n", 2);
        }
    }
}
