/*
** EPITECH PROJECT, 2020
** env to list
** File description:
** create a linked list with the env variables
*/

#include "minishell.h"

/*
** node creation with datas as arguments, the nodes will be added at the
** end of the list
** starting from the head, we will adjust the pointers of head and tail to
** keep it true
*/

node_t *create_node(char *variable, char *value)
{
    node_t *element;

    element = malloc(sizeof(node_t));
    if (element == NULL) {
        write(2, "malloc from create node failed\n", 32);
        return (NULL);
    }
    element->variable = variable;
    element->value = value;
    element->next = NULL;
    return (element);
}

node_t *add_node_at_end(node_t *begin_node, char *variable, char *value,
                                                        linked_list_t *list)
{
    node_t *new_node = create_node(variable, value);

    if (new_node == NULL) {
        write(2, "malloc from add node at end failed\n", 36);
        return (NULL);
    }
    list->tail->next = new_node;
    new_node->next = NULL;
    list->tail = new_node;
    return (begin_node);
}

/*
** we create a list with as data :
** the variable and it's value as strings
** we are getting them by putting the line in an array of strings separated
** by '=' (the array is called component)
** it is a copy of the env we had to my_strdup it to not modify our actual env
** we are creating a linked list so we can add a variable and value if
** needed by the user
*/

char **get_components(char *line)
{
    char **components = malloc(sizeof(char *) * 3);
    int var_size = 0;

    while (line[var_size] != '=')
        var_size++;
    components[1] = my_strdup(&line[var_size + 1]);
    line[var_size] = 0;
    components[0] = my_strdup(line);
    components[2] = NULL;
    return (components);
}

linked_list_t *env_to_list(linked_list_t *list, char **env)
{
    int var_count = 0;
    char **components = get_components(env[var_count++]);
    char *variable = components[0];
    char *value = components[1];

    list->head = create_node(my_strdup(variable), my_strdup(value));
    list->tail = list->head;
    free_tab(components);
    while (env[var_count] != NULL) {
        components = get_components(env[var_count]);
        if (components == NULL || list->head == NULL)
            return (NULL);
        variable = my_strdup(components[0]);
        value = my_strdup(components[1]);
        var_count++;
        list->head = add_node_at_end(list->head, variable, value, list);
        free_tab(components);
    }
    return (list);
}

/*
** init the list with two empty nodes that are the head and the tail of the
** list when referencing node_t we are pointing to a specific node
** when referencing on list->tail /list->head we are pointing on the head or
** the tail of the list
*/

linked_list_t *create_env_list(char **env)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    if (list == NULL) {
        write(2, "malloc from create env list failed\n", 36);
        return (NULL);
    }
    list->head = NULL;
    list->tail = NULL;
    list = env_to_list(list, env);
    if (list == NULL)
        return (NULL);
    return (list);
}