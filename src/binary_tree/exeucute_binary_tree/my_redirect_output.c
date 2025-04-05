/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** my_redirect_output
*/
#include "binary.h"
#include "command.h"

int execute_redirect(char **child,
    char *filename, binary_tree_node_t *child_bin, all_t *all)
{
    pid_t cpid;
    int status;
    int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0777);

    cpid = fork();
    if (cpid == 0) {
        dup2(fd, STDOUT_FILENO);
        if (!is_separator(child[0])) {
            execute_with_builtins(child, all);
        } else {
            execute_binary_tree(child_bin, all);
        }
        exit(0);
    } else {
        waitpid(cpid, &status, 0);
        close(fd);
    }
}

int execute_redirect_bis(char **child,
    char *filename, binary_tree_node_t *child_bin, all_t *all)
{
    pid_t cpid;
    int status;
    int fd = open(filename, O_CREAT | O_APPEND | O_RDWR, 0777);

    cpid = fork();
    if (cpid == 0) {
        dup2(fd, STDOUT_FILENO);
        if (!is_separator(child[0])) {
            execute_with_builtins(child, all);
            exit(84);
        } else {
            execute_binary_tree(child_bin, all);
            exit(0);
        }
    } else {
        waitpid(cpid, &status, 0);
        close(fd);
    }
}

void my_redirection(char *cmd, char *file, binary_tree_node_t *child_bin,
    all_t *all)
{
    char **child_cmd = my_str_to_word_array(cmd, " \t\n");

    execute_redirect(child_cmd, file, child_bin, all);
}

void my_redirection_bis(char *cmd, char *file, binary_tree_node_t *child_bin,
    all_t *all)
{
    char **child_cmd = my_str_to_word_array(cmd, " \t\n");

    execute_redirect_bis(child_cmd, file, child_bin, all);
}
