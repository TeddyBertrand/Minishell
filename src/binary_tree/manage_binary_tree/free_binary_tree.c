/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** free_binary_tree
*/
#include "binary.h"

void free_binary_tree(binary_tree_node_t *node)
{
    if (node == NULL)
        return;
    free_binary_tree(node->left);
    free_binary_tree(node->right);
    free(node->data);
    free(node);
}
