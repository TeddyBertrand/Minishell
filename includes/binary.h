/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <sys/wait.h>
    #include <string.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include "struct.h"

typedef enum {
    NOTHING = 0,
    PIPE,
    OUTPUT,
    INPUT,
    OUTPUT_APPEND,
    INPUT_EOF,
    STDERR,
} separator_t;

void my_redirection_stderr(char *cmd, char *file, binary_tree_node_t *child_bin, all_t *all);
char *strndup_with_indexes(const char *src, int start, int end);
char **my_str_to_word_array(char *str, char *delim);
void execute_binary_tree(binary_tree_node_t *binary_tree, all_t *bools);
binary_tree_node_t *create_binary_tree(char *current_binary);
bool is_separator(char *data);
int which_separator(char *data, int i);
char *the_strdup(int separator);
char *pretty_string(char *str);
void my_redirection(char *cmd, char *file, binary_tree_node_t *child_bin,
    all_t *all);
void my_redirection_bis(char *cmd, char *file, binary_tree_node_t *child_bin,
    all_t *all);
int which_use(char *data);
void execute_unique(char *command, all_t *bools);
bool no_more_separator(char *current_binary, int i);
void print_binary_tree(binary_tree_node_t *node, int level,
    const char *prefix);
int my_pipe(binary_tree_node_t *child, binary_tree_node_t *parent,
    all_t *bools);
void my_input_redirect(char *cmd, char *file, binary_tree_node_t *child_bin,
    all_t *all);
int which_use(char *data);
#endif
