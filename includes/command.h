/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** command
*/

#ifndef COMMAND_H
    #define COMMAND_H
    #include <includes.h>
    #include <struct.h>

int my_commands(char **commande, all_t *bools);
int commande_cd(char **commande, all_t *bools);
char *get_home_parser(char **env);
void print_env(char **env);
int set_env(all_t *bools, char *varenv, char *infoenv);
int unset_env(all_t *bools, char *varenv);
void free_env(char **env);
int doesitexist(char **env, char *var);
int my_commands_env(all_t *bools, char **commande);
int cd_home(char **commande, all_t *bools);
int cd_back(char **commande, all_t *bools);
int changeenv(all_t *bools, char **commande);
char *get_oldpwd_parser(char **env);
int my_exit(all_t *bools, char **commande);
int execute_with_builtins(char **commande, all_t *bools);
#endif
