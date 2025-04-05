/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** struct
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include "includes.h"

typedef struct binary_tree_node_s {
    char *data;
    struct binary_tree_node_s *left;
    struct binary_tree_node_s *right;
} binary_tree_node_t;

typedef struct all {
    bool exit;
    char **env;
    char *pwd;
    char *oldpwd;
    int indexvar;
    int indexpassed;
    bool speflag;
    char *alcool;
    bool erroroldpwd;
    bool errorhome;
    int status;
    bool wrongcd;
    int segmented;
    char *path;
    binary_tree_node_t *binary;
} all_t;

#endif
