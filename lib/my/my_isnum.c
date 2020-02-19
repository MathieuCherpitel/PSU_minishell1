/*
** EPITECH PROJECT, 2020
** my isnum
** File description:
** checks if the string is a number
*/

int my_isnum(char *string)
{
    int count = 0;

    while (string[count] != 0) {
        if (string[count] < 48 || string[count] > 57)
            return (0);
        count++;
    }
    return (1);
}
