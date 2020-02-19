/*
** EPITECH PROJECT, 2020
** setenv
** File description:
** sets the value of an env variable
*/

#include "minishell.h"

int set_existing_var(char *variable, char *value, linked_list_t *list)
{
    node_t *tmp = list->head;

    while (tmp != NULL) {
        if (my_strcmp(tmp->variable, variable) == 0) {
            tmp->value = value;
            return (0);
        }
        tmp = tmp->next;
    }
    return (1);
}

void free_strings(char **tab, char *variable, char *value)
{
    free(tab);
    free(variable);
    free(value);
}

int set_env_value(char *input, linked_list_t *list)
{
    char **args = my_str_to_word_array(input, " ");
    char *variable = my_strdup(args[1]);
    char *value = my_strdup(args[2]);

    if (variable == NULL || args == NULL) {
        free_strings(args, variable, value);
        return (ERR);
    }
    if (set_existing_var(variable, value, list) == 0) {
        free(args);
        return (0);
    }
    list->head = add_node_at_end(list->head, variable, value, list);
    if (list->head == NULL) {
        free_strings(args, variable, value);
        return (ERR);
    }
    return (0);
}

int check_setenv(char *command)
{
    char **args = my_str_to_word_array(command, " ");

    if ((args[1] == NULL && my_strcmp(args[0], "setenv") == 0)
        || my_strcmp(command, " ") == 0)
        return (2);
    if (args[1][0] < 65 || (args[1][0] > 90
                        && args[1][0] < 97) || args[1][0] > 122) {
        if (args[1][0] != '_') {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            return (1);
        }
    }
    if (my_isalpha(args[1]) != 0 || my_isnum(args[1]) != 0) {
        if (args[1][0] != '_') {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}

int my_setenv(char *input, linked_list_t *list)
{
    char **env = NULL;
    char **args = my_str_to_word_array(input, " ");
    int return_value = 0;
    int tab_size = get_tab_size(args);

    if (tab_size > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (1);
    }
    return_value = check_setenv(input);
    if (tab_size == 1) {
        env = list_to_arr(list);
        return_value = print_env(NULL, list);
        free_tab(env);
        return (return_value);
    }
    if (return_value != 1)
        return_value = set_env_value(input, list);
    free_tab(args);
    return (return_value);
}