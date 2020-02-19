/*
** EPITECH PROJECT, 2020
** clean string
** File description:
** clean the string in case of t many spaces
*/

#include "minishell.h"

/*
** this functions cleans the string of the uselese spaces
*/

char *remove_spaces(char *string, int count)
{
    char *clean_string = malloc(sizeof(char) * (my_strlen(string) + 1));
    char *next_part = NULL;
    int i = 0;

    clean_string = my_strncpy(clean_string, string, count);
    clean_string[count] = 0;
    while (string[count + i] == ' ')
        i++;
    next_part = my_strdup(&string[count + i - 1]);
    clean_string = my_strcat(clean_string, next_part);
    free(next_part);
    return (clean_string);
}

char *remove_tab(char *string)
{
    int count = 0;

    while (string[0] == '\t')
        string++;
    while (string[count] != '\n') {
        if (string[count] == '\t')
            string[count] = ' ';
        count++;
    }
    return (string);
}

char *clean_string(char *string)
{
    int count = 0;
    char *copy;

    while (string[0] == ' ')
        string++;
    copy = my_strdup(string);
    copy = remove_tab(copy);
    while (copy[count] != '\n') {
        if (copy[count] == ' ' && copy[count + 1] == ' ') {
            copy = remove_spaces(copy, count);
            count = 0;
        }
        count++;
    }
    copy[count] = 0;
    if (copy[count - 1] == ' ')
        copy[count - 1] = 0;
    return (copy);
}

char *format_string(char *buffer)
{
    int count = 0;
    char *formated_string;

    while (buffer[count] != 0) {
        if (buffer[count] == '\n')
            return (buffer);
        count++;
    }
    formated_string = malloc(sizeof(char) * my_strlen(buffer) + 2);
    formated_string = my_strcpy(formated_string, buffer);
    formated_string[my_strlen(buffer)] = '\n';
    formated_string[my_strlen(buffer) + 1] = 0;
    free(buffer);
    return (formated_string);
}