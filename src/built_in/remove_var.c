/*
** EPITECH PROJECT, 2020
** remove var
** File description:
** used in unsetenv
*/

#include "minishell.h"

node_t *remove_node_at_middle(node_t *begin_node, char *variable)
{
    node_t *tmp = begin_node;
    node_t *save_tmp = tmp;

    if (begin_node == NULL)
        return (NULL);
    while (my_strcmp(variable, tmp->variable) != 0 && tmp->next != NULL) {
        save_tmp = tmp;
        tmp = tmp->next;
    }
    if (tmp->next == NULL)
        return (NULL);
    save_tmp->next = tmp->next;
    free(tmp);
    return (begin_node);
}

node_t *remove_node_at_begin(node_t *begin_node, linked_list_t *list)
{
    node_t *tmp = begin_node;

    if (begin_node == NULL)
        return (NULL);
    tmp = begin_node->next;
    list->head = tmp;
    free(begin_node);
    return (list->head);
}

node_t *remove_node_at_end(node_t *begin_node, node_t *last_node,
                                                    linked_list_t *list)
{
    node_t *tmp = begin_node;

    if (last_node == begin_node) {
        free(begin_node);
        return (NULL);
    }
    while (tmp->next != last_node)
        tmp = tmp->next;
    tmp->next = NULL;
    list->tail = tmp;
    free(last_node);
    return (list->tail);
}

void remove_node(char *variable, linked_list_t *list)
{
    if (my_strcmp(variable, list->head->variable) == 0) {
        list->head = remove_node_at_begin(list->head, list);
        return;
    }
    if (my_strcmp(variable, list->tail->variable) == 0) {
        list->tail = remove_node_at_end(list->head, list->tail, list);
        return;
    }
    else {
        list->head = remove_node_at_middle(list->head, variable);
        return;
    }
}