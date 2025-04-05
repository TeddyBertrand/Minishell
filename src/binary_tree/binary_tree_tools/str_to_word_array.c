/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** str_to_word_array
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>
#include "tools.h"

static int count_words(char *str, char *delim)
{
    int count = 0;
    char *temp = my_strdup(str);
    char *token = strtok(temp, delim);

    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }
    free(temp);
    return count;
}

char **my_str_to_word_array(char *str, char *delim)
{
    int words = count_words(str, delim);
    char **array = malloc((words + 1) * sizeof(char *));
    char *temp = my_strdup(str);
    char *token = strtok(temp, delim);
    int i = 0;

    for (; token != NULL; i++) {
        array[i] = my_strdup(token);
        token = strtok(NULL, delim);
    }
    array[i] = NULL;
    free(temp);
    return array;
}
