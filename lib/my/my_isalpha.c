/*
** EPITECH PROJECT, 2020
** my isalpha
** File description:
** returns 0 is the string s only alphanumerical
*/

#include "libmy.h"

int my_isalpha(char *str)
{
    int count = 0;

    while (str[count] != 0) {
        if ((str[count] < 65 || str[count] > 90)
            && (str[count] < 97 || str[count] > 122))
            return (1);
        count++;
    }
    return (0);
}