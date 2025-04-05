/*
** EPITECH PROJECT, 2025
** binary_tree
** File description:
** my_strndup_with_indexes
*/
#include "binary.h"

char *strndup_with_indexes(const char *src, int start, int end)
{
    int new_len = end - start + 1;
    char *dest = malloc(sizeof(char) * (new_len + 1));

    for (int i = 0; i < new_len; i++) {
        dest[i] = src[start + i];
    }
    dest[new_len] = '\0';
    return dest;
}
