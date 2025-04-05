/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Ecrire un nombre quel qu'il soit
*/
#include "tools.h"

int my_put_nbr(int nb)
{
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-(nb));
        return (0);
    }
    my_put_nbr(nb / 10);
    my_put_nbr(nb - ((nb / 10)) * 10);
    return (0);
}
