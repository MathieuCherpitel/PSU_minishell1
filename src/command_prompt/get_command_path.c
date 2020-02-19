/*
** EPITECH PROJECT, 2020
** call command
** File description:
** checks in the PATH set in env if there is is a binary and execve it (fork)
*/

#include <dirent.h>
#include "minishell.h"

char **get_paths(linked_list_t *list)
{
    node_t *tmp = list->head;
    char **paths;

    while (my_strcmp(tmp->variable, "PATH") != 0 && tmp->next != NULL)
        tmp = tmp->next;
    if (tmp->value == NULL || tmp->next == NULL)
        return (NULL);
    paths = my_str_to_word_array(tmp->value, ":");
    if (paths == NULL) {
        write(2, "malloc error at get paths\n", 27);
        return (NULL);
    }
    return (paths);
}

int find_command(char *command, char *path)
{
    DIR *directory;
    struct dirent *directory_data = NULL;

    directory = opendir(path);
    if (directory != NULL)
        directory_data = readdir(directory);
    while (directory_data != NULL) {
        if (my_strcmp(command, directory_data->d_name) == 0) {
            closedir(directory);
            return (TRUE);
        }
        directory_data = readdir(directory);
    }
    closedir(directory);
    return (FALSE);
}

char *get_command_path(char **args, linked_list_t *list)
{
    char **paths = get_paths(list);
    char *command = args[0];
    int path_status = FALSE;
    int count = 0;

    if (paths == NULL)
        return (NULL);
    while (paths[count] != NULL && path_status == FALSE) {
        path_status = find_command(command, paths[count]);
        if (path_status == ERR)
            return (NULL);
        if (path_status == TRUE)
            return (paths[count]);
        count++;
    }
    return (NULL);
}