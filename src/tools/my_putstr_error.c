/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell2-teddy.bertrand
** File description:
** my_putstr_error
*/
#include "includes.h"

void my_putstr_error(char *str, int fd)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(fd, &str[i], 1);
}
