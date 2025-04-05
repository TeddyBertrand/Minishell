/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** my_execute
*/
#include "binary.h"
#include "main.h"
#include "command.h"

void execute_binary_tree(binary_tree_node_t *binary_tree, all_t *bools)
{
    int separator;

    if (is_separator(binary_tree->data)) {
        separator = which_use(binary_tree->data);
        if (separator == PIPE) {
            my_pipe(binary_tree->left, binary_tree->right, bools);
        }
        if (separator == OUTPUT) {
            my_redirection(binary_tree->left->data,
                binary_tree->right->data, binary_tree->left, bools);
        }
        if (separator == OUTPUT_APPEND) {
            my_redirection_bis(binary_tree->left->data,
                binary_tree->right->data, binary_tree->left, bools);
        }
        if (separator == INPUT) {
            my_input_redirect(binary_tree->left->data,
                binary_tree->right->data, binary_tree->left, bools);
        }
        if (separator == INPUT) {
            my_input_redirect(binary_tree->left->data,
                binary_tree->right->data, binary_tree->left, bools);
        }
        if (separator == STDERR) {
            my_redirection_stderr(binary_tree->left->data,
                binary_tree->right->data, binary_tree->left, bools);
        }
    }
}

void execute_unique(char *command, all_t *bools)
{
    pid_t cpid;
    int status;
    char *new_parent = pretty_string(command);
    char **parent_cmd = my_str_to_word_array(new_parent, " \t\n");

    if (my_commands(parent_cmd, bools) == 0)
        return;
        parent_cmd[0] = is_accessible(bools, parent_cmd[0]);
        if (parent_cmd[0] == NULL)
        return;
        set_fork(bools, parent_cmd);
}
