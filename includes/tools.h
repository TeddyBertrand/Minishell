/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** tools
*/

#ifndef TOOLS_H
    #define TOOLS_H
    #include "includes.h"

char **my_str_to_word_array(char *str, char *delim);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int mini_printf(const char *format, ...);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
int my_strlen(char *str);
char *my_strdup(char *src);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
char **my_strdup_array(char **argv);
void my_putstr_error(char *str, int fd);
char *my_strdup(char *str);
#endif
