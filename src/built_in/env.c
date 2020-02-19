/*
** EPITECH PROJECT, 2020
** env built in command
** File description:
** prints the env
*/

#include "minishell.h"

void print_list(linked_list_t *list)
{
    node_t *tmp = list->head;

    while (tmp != NULL) {
        if (tmp->variable != NULL) {
            my_putstr(tmp->variable);
            my_putchar('=');
        }
        if (tmp->value != NULL)
            my_putstr(tmp->value);
        my_putchar('\n');
        tmp = tmp->next;
    }
}