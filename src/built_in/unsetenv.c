/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** removes a node from the env list
*/

#include "minishell.h"

int check_exist_var(char *variable, linked_list_t *list)
{
    node_t *tmp = list->head;

    while (tmp != NULL) {
        if (my_strcmp(tmp->variable, variable) == 0)
            return (TRUE);
        tmp = tmp->next;
    }
    return (FALSE);
}

int my_unsetenv(char *input, linked_list_t *list)
{
    char **args = my_str_to_word_array(input, " ");
    int tab_size = get_tab_size(args);
    int count = 1;

    if (tab_size == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (1);
    }
    while (count < tab_size) {
        if (check_exist_var(args[count], list) == TRUE)
            remove_node(args[count], list);
        count++;
    }
    return (SUCCESS);
}