/*
** EPITECH PROJECT, 2020
** strscpy
** File description:
** copies every char before " "
*/

#include "libmy.h"

char *my_strscpy(char *str)
{
    int len = 0;
    char *dest;

    while (str[len] != ' ' && str[len] != 0)
        len++;
    if (len == my_strlen(str))
        return (str);
    dest = malloc(sizeof(char) * (len + my_strlen(str) + 1));
    if (dest == NULL)
        return (NULL);
    dest = my_strncpy(dest, str, len);
    dest[len] = 0;
    return (dest);
}