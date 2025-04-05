/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** useful_tools_bis
*/
#include "binary.h"
#include "tools.h"

int which_separator(char *data, int i)
{
    if (data[i] == '>') {
        if (data[i - 1] == '>')
        return OUTPUT_APPEND;
        if (data[i - 1] == '2')
        return STDERR;
        return OUTPUT;
    }
    if (data[i] == '<')
        if (data[i - 1] == '<')
        return INPUT_EOF;
        else
        return INPUT;
    if (data[i] == '|')
    return PIPE;
    return NOTHING;
}

char *the_strdup(int separator)
{
    if (separator == PIPE)
    return my_strdup("|");
    if (separator == OUTPUT)
    return my_strdup(">");
    if (separator == INPUT)
    return my_strdup("<");
    if (separator == OUTPUT_APPEND)
    return my_strdup(">>");
    if (separator == INPUT_EOF)
    return my_strdup("<<");
    if (separator == STDERR)
    return my_strdup("2>");
}

char *pretty_string(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char *str_but_better;

    for (; str[i] == ' '; i++);
    for (; str[j] == ' ' || str[j] == '\n'; j--);
    str_but_better = strndup_with_indexes(str, i, j);
    return str_but_better;
}
