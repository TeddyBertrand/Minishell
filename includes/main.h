/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** main
*/

#ifndef MAIN_H
    #define MAIN_H
    #include "includes.h"
    #include "struct.h"
    #include "binary.h"

void init_all(all_t *bools, char **env);
int minishell(all_t *bools);
char *is_accessible(all_t *bools, char *commande);
void set_fork(all_t *bools, char **commande);
void print_help(void);
char *getpath(char *token, char *buff, char *commande);
int my_tcsh(int argc, char **argv, char **env);
void get_status(all_t *bools, int status);
#endif
