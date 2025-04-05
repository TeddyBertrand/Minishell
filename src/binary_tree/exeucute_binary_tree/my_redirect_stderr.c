/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** my_redirect_stderr
*/

#include "binary.h"
#include "command.h"

int execute_redirect_stderr(char **child,
    char *filename, binary_tree_node_t *child_bin, all_t *all)
{
    pid_t cpid;
    int status;
    int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0777);

    cpid = fork();
    if (cpid == 0) {
        dup2(fd, STDERR_FILENO);
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

void my_redirection_stderr(char *cmd, char *file, binary_tree_node_t *child_bin,
    all_t *all)
{
    char **child_cmd = my_str_to_word_array(cmd, " \t\n");

    execute_redirect_stderr(child_cmd, file, child_bin, all);
}
