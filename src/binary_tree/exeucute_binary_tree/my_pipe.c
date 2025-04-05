/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** my_pipe
*/
#include "binary.h"
#include "main.h"
#include "command.h"

int execute_with_builtins(char **commande, all_t *bools)
{
    if (my_commands(commande, bools) == 0)
        exit(0);
    commande[0] = is_accessible(bools, commande[0]);
    if (commande[0] == NULL)
        exit(0);
    set_fork(bools, commande);
}

int child_exec(int *pipefd, all_t *bools, char **child,
    binary_tree_node_t *child_bin)
{
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    if (!is_separator(child[0])) {
        execute_with_builtins(child, bools);
    } else {
        execute_binary_tree(child_bin, bools);
    }
    exit(0);
}

int parent_exec(int *pipefd, all_t *bools, char **parent)
{
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    execute_with_builtins(parent, bools);
}

int execute_command(all_t *bools, char **child,
    char **parent, binary_tree_node_t *child_bin)
{
    int *pipefd;
    pid_t cpid;

    pipe(pipefd);
    cpid = fork();
    if (cpid == 0) {
        child_exec(pipefd, bools, child, child_bin);
    } else {
        parent_exec(pipefd, bools, parent);
    }
}

int my_pipe(binary_tree_node_t *child, binary_tree_node_t *parent,
    all_t *bools)
{
    int pipefd[2];
    int status;
    char **parent_cmd;
    char **child_cmd;
    pid_t cpid;

    cpid = fork();
    parent_cmd = my_str_to_word_array(parent->data, " \t\n");
    child_cmd = my_str_to_word_array(child->data, " \t\n");
    if (cpid == 0) {
        execute_command(bools, child_cmd, parent_cmd, child);
        exit(0);
    } else {
        waitpid(cpid, &status, 0);
    }
}
