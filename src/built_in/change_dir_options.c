/*
** EPITECH PROJECT, 2020
** change dir options
** File description:
** call functions for - ~ or dir options
*/

#include <unistd.h>
#include "minishell.h"

void set_env_data(linked_list_t *list, char *variable, char *value)
{
    node_t *tmp = list->head;

    while (my_strcmp(tmp->variable, variable) != 0 && tmp->next != NULL)
        tmp = tmp->next;
    if (tmp->next == NULL)
        return;
    free(tmp->value);
    tmp->value = my_strdup(value);
}

int change_dir_home(linked_list_t *list, char *HOME, char *PWD)
{
    char *home = my_strdup(HOME);
    char *pwd = my_strdup(PWD);
    size_t bufsize = 200;
    char *buffer = malloc(sizeof(char) * bufsize + 1);

    if (buffer == NULL)
        return (ERR);
    if (chdir(home) == -1)
        return (ERR);
    set_env_data(list, "PWD", home);
    set_env_data(list, "OLDPWD", pwd);
    free(buffer);
    free(home);
    return (SUCCESS);
}

int change_dir_old(linked_list_t *list, char *OLDPWD, char *PWD)
{
    char *old = my_strdup(OLDPWD);
    char *pwd = my_strdup(PWD);

    if (chdir(old) == -1)
        return (ERR);
    set_env_data(list, "PWD", old);
    set_env_data(list, "OLDPWD", pwd);
    free(pwd);
    free(old);
    return (SUCCESS);
}

int change_dir_normal(linked_list_t *list, char *directory, char *PWD)
{
    char *pwd = my_strdup(PWD);
    size_t bufsize = 200;
    char *buffer = malloc(sizeof(char) * bufsize + 1);

    if (get_oldpwd(list) == NULL)
        my_setenv(my_strcat("OLDPWD", getcwd(buffer, bufsize)), list);
    if (buffer == NULL)
        return (ERR);
    if (chdir(directory) == -1)
        return (ERR);
    set_env_data(list, "OLDPWD", pwd);
    set_env_data(list, "PWD", getcwd(buffer, bufsize));
    free(pwd);
    free(buffer);
    return (SUCCESS);
}