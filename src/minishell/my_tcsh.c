/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** my_tcsh
*/
#include <tools.h>
#include <struct.h>
#include <main.h>

int my_tcsh(int argc, char **argv, char **env)
{
    all_t *bools = malloc(sizeof(all_t));
    int status;

    if (bools == NULL)
    return (84);
    init_all(bools, env);
    if (argc != 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            print_help();
        else
            return (1);
    }
    while (bools->exit == false) {
        minishell(bools);
        if (!isatty(0) && bools->status != 0)
        return (bools->status);
    }
    status = bools->status;
    free(bools);
    return status;
}
