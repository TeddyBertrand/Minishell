/*
** EPITECH PROJECT, 2024
** my_miniprintf.c
** File description:
** my own miniprintf
*/
#include "tools.h"

int pourcentagesuite(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
        case 'd':
            my_put_nbr(va_arg(list, int));
            break;
        case 'i':
            my_put_nbr(va_arg(list, int));
            break;
        default:
            my_putchar('%');
            break;
    }
    return (0);
}

int pourcentage(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
        case 's':
            my_putstr(va_arg(list, char *));
            break;
        case 'c':
            my_putchar(va_arg(list, int));
            break;
        default:
            pourcentagesuite(format, i, list);
            break;
    }
    return (0);
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            pourcentage(format, i, list);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(list);
    return (0);
}
