/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** my_exit
*/

#include <struct.h>
#include <tools.h>
#include <command.h>

int is_numeric(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (0);
        }
    }
    return (1);
}

int my_exit(all_t *bools, char **commande)
{
    if (commande[2] != NULL) {
        mini_printf("exit: Expression Syntax.\n");
        bools->status = 1;
        return (0);
    }
    if (commande[1] != NULL) {
        if (is_numeric(commande[1]) == 1) {
            bools->status = my_getnbr(commande[1]);
            mini_printf("exit\n");
            bools->exit = true;
        } else {
            mini_printf("exit: Expression Syntax.\n");
            bools->status = 1;
        }
    } else {
        bools->status = 0;
        mini_printf("exit\n");
        bools->exit = true;
    }
    return (0);
}
