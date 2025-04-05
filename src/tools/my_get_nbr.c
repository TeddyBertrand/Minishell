/*
** EPITECH PROJECT, 2024
** B-CPE-110-MPL-1-1-bssettingup-teddy.bertrand
** File description:
** my_get_nbr.c
*/
#include <includes.h>

int numbers(int i, char const *str, int moins, int nbr)
{
    while (str[i] >= '0' && str[i] <= '9') {
        nbr = (nbr * 10) + str[i] - 48;
        i = i + 1;
        if (nbr == -2147483648) {
            return (nbr);
        }
    }
    if (moins > 0 && moins % 2 == 1) {
    nbr = -nbr;
    }
    return (nbr);
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int moins = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = numbers(i, str, moins, nbr);
            return (nbr);
        }
        if (str[i] == '-')
        moins++;
        if (str[i] != '-' && str[i] != '+')
        return (0);
    }
    return (0);
}
