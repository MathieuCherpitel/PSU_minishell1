/*
** EPITECH PROJECT, 2020
** include main functions
** File description:
** include file for main functions file
*/

#ifndef _MAIN_FUNCTIONS_H_
#define _MAIN_FUNCTIONS_H_

// struct file include
#include "structs.h"

// functions includes from env to list
node_t *create_node(char *variable, char *value);
node_t *add_node_at_end(node_t *begin_node, char *variable, char *value,
                                                    linked_list_t *list);
linked_list_t *env_to_list(linked_list_t *list, char **env);
linked_list_t *create_env_list(char **env);


// functions includes from minishell
int minishell(char **env);

#endif /* !_MAIN_FUNCTIONS_H_ */