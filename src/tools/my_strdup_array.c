/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** my_strdup_array
*/
#include <tools.h>

int lenarray(char **argv)
{
    int i = 0;

    for (; argv[i] != NULL; i++);
    return (i);
}

char **my_strdup_array(char **argv)
{
    char **dup;
    int i = 0;
    int nb_mots = lenarray(argv);

    dup = malloc(sizeof(char *) * (nb_mots + 1));
    for (; argv[i] != NULL; i++)
        dup[i] = my_strdup(argv[i]);
    dup[i] = NULL;
    return (dup);
}
