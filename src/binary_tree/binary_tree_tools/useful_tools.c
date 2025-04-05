/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** useful_tools
*/
#include "binary.h"
#include "tools.h"

bool no_more_separator(char *current_binary, int i)
{
    for (int j = 0; j < i; j++) {
        if (which_separator(current_binary, j) != 0)
        return 0;
    }
    return 1;
}

int which_use(char *data)
{
    if (data[0] == '>') {
        if (data[1] == '>')
        return OUTPUT_APPEND;
        if (data[1] == '2')
        return STDERR;
        return OUTPUT;
    }
    if (data[0] == '<')
        if (data[1] == '<')
        return INPUT_EOF;
        else
        return INPUT;
    if (data[0] == '|')
    return PIPE;
    return NOTHING;
}

bool is_separator(char *data)
{
    char *separators[] = {"|", "<", ">", "<<", ">>", NULL};

    for (int i = 0; separators[i] != NULL; i++) {
        if (my_strcmp(separators[i], data) == 0) {
            return true;
        }
    }
    return false;
}
