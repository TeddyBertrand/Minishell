/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** my_redirct_input
*/
#include "binary.h"
#include "command.h"

int execute_the_redirect(int fd, char **child, binary_tree_node_t *child_bin,
    all_t *all)
{
    int status;
    pid_t cpid = fork();

    if (cpid == 0) {
        dup2(fd, STDIN_FILENO);
        close(fd);
        if (!is_separator(child[0])) {
            execute_with_builtins(child, all);
            exit(0);
        } else {
            execute_binary_tree(child_bin, all);
            exit(0);
        }
    } else {
        waitpid(cpid, &status, 0);
        close(fd);
    }
}

int execute_input_redirect(char **child,
    char *filename, binary_tree_node_t *child_bin, all_t *all)
{
    int fd = open(filename, O_RDONLY);
    pid_t cpid = fork();
    int status;

    if (cpid == 0) {
        if (fd == -1) {
            perror("open");
            return -1;
        }
        execute_the_redirect(fd, child, child_bin, all);
        exit(0);
    } else {
        waitpid(cpid, &status, 0);
    }
}

void my_input_redirect(char *cmd, char *file, binary_tree_node_t *child_bin,
    all_t *all)
{
    char **child_cmd = my_str_to_word_array(cmd, " \t\n");

    execute_input_redirect(child_cmd, file, child_bin, all);
}
