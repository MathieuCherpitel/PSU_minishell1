/*
** EPITECH PROJECT, 2020
** list to tab
** File description:
** puts the linked list into an array
*/

#include "minishell.h"

void free_tab(char **tab)
{
    int count = 0;

    while (tab[count] != NULL) {
        free(tab[count]);
        count++;
    }
    free(tab);
}

int get_list_size(linked_list_t *list)
{
    node_t *tmp = list->head;
    int list_size = 0;

    while (tmp->next != NULL) {
        tmp = tmp->next;
        list_size++;
    }
    return (list_size);
}

char *concat_strings(char *variable, char *value)
{
    char *line;

    if (value != NULL)
        line = malloc(sizeof(char) * (my_strlen
                            (variable) + my_strlen(value) + 2));
    else
        line = malloc(sizeof(char) * (my_strlen(variable) + 2));
    line = my_strcpy(line, variable);
    line = my_strcat(line, "=");
    if (value != NULL)
        line = my_strcat(line, value);
    return (line);
}

char **list_to_arr(linked_list_t *list)
{
    int list_size = get_list_size(list);
    int count = 0;
    node_t *tmp = list->head;
    char **env;

    list_size++;
    env = malloc(sizeof(char *) * (list_size + 1));
    while (tmp->next != NULL) {
        if (tmp->variable != NULL) {
            env[count] = concat_strings(tmp->variable, tmp->value);
            count++;
        }
        tmp = tmp->next;
    }
    env[count] = NULL;
    return (env);
}