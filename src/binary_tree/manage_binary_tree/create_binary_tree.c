/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** create_binary_tree
*/
#include "binary.h"
#include "tools.h"

static bool is_there_nothing(char *str)
{
    if (str[0] == '\0')
        return true;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ' || str[i] == '\n' ||
            str[i] == '\t' || str[i] == '\0')
            continue;
        else
        return false;
    return true;
}

static bool good_parent(char *data)
{
    if (data == NULL || is_there_nothing(data))
        return false;
    return true;
}

binary_tree_node_t *simple_branch_creation(int separator, char *current_binary,
    int i, binary_tree_node_t *node)
{
    char *data;
    int sep_len = my_strlen(the_strdup(separator));
    int len = my_strlen(current_binary);

    node->data = the_strdup(separator);
    data = strndup_with_indexes(current_binary, i + 1, len);
    node->right = malloc(sizeof(binary_tree_node_t));
    node->right->data = pretty_string(data);
    if (!good_parent(data))
        return NULL;
    data = strndup_with_indexes(current_binary, 0, i - sep_len);
    node->left = create_binary_tree(data);
    return node;
}

binary_tree_node_t *last_branch_creation(int separator, char *current_binary,
    int i, binary_tree_node_t *node)
{
    char *data;
    int sep_len = my_strlen(the_strdup(separator));
    int len = my_strlen(current_binary);

    node->data = the_strdup(separator);
    data = strndup_with_indexes(current_binary, 0, i - sep_len);
    node->left = malloc(sizeof(binary_tree_node_t));
    node->left->data = pretty_string(data);
    data = strndup_with_indexes(current_binary, i + 1, len);
    node->right = malloc(sizeof(binary_tree_node_t));
    node->right->data = pretty_string(data);
    if (!good_parent(data))
        return NULL;
    return node;
}

binary_tree_node_t *which_creation(char *current_binary, int separator,
    int i, binary_tree_node_t *node)
{
    if (!no_more_separator(current_binary, i)) {
        return simple_branch_creation(separator, current_binary, i, node);
    } else {
        return last_branch_creation(separator, current_binary, i, node);
    }
}

binary_tree_node_t *create_binary_tree(char *current_binary)
{
    binary_tree_node_t *node = malloc(sizeof(binary_tree_node_t));
    int len = my_strlen(current_binary);
    int sep_len = 0;
    int separator = 0;
    char *data;

    node->left = NULL;
    node->right = NULL;
    for (int i = len; i >= 0; i--) {
        separator = which_separator(current_binary, i);
        if (separator != 0) {
            sep_len = my_strlen(the_strdup(separator));
            return which_creation(current_binary, separator, i, node);
        }
    }
    node->data = current_binary;
    return node;
}
