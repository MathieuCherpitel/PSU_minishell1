/*
** EPITECH PROJECT, 2020
** access tests
** File description:
** tests the acces rights
*/

#include "minishell.h"

int normal_command_access(char *input)
{
    if (access(input, X_OK) != 0) {
        my_putstr(input);
        my_putstr(": Permission denied.\n");
        return (1);
    }
    return (SUCCESS);
}

int binary_command_access(char *command_path, char *input)
{
    char *to_test = my_strdup(input);
    to_test = get_complete_command(to_test, command_path);

    if (access(to_test, X_OK) != 0) {
        my_putstr(input);
        my_putstr(": Permission denied.\n");
        free(to_test);
        return (1);
    }
    return (SUCCESS);
}

char *get_complete_command(char *input, char *command_path)
{
    char *to_test;

    if (input == NULL && command_path == NULL)
        return (NULL);
    to_test = malloc(sizeof(char) * (my_strlen
                                    (command_path) + my_strlen(input) + 2));
    if (to_test == NULL)
        return (NULL);
    to_test = my_strcpy(to_test, command_path);
    to_test = my_strcat(to_test, "/");
    to_test = my_strcat(to_test, input);
    return (to_test);
}

int print_errors(char *input, char *command_path)
{
    int is_dire_command = check_dire_command(input);

    if (input == NULL || command_path == NULL) {
        my_putstr(input);
        my_putstr(": Command not found.\n");
        return (1);
    }
    if (is_dire_command == TRUE) {
        if (access(input, F_OK) ==  -1) {
            my_putstr(input);
            my_putstr(": Command not found.\n");
            return (1);
        }
    }
    if (my_strncmp(input, "./", 1) == 0 || is_dire_command == TRUE)
        return (normal_command_access(input));
    else
        return (binary_command_access(command_path, input));
    return (SUCCESS);
}