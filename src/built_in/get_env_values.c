/*
** EPITECH PROJECT, 2020
** get env values
** File description:
** checks and get the env values
*/

#include "minishell.h"

char *get_env_value(linked_list_t *list, char *value)
{
    node_t *tmp = list->head;

    while (tmp != NULL) {
        if (my_strcmp(tmp->variable, value) == 0)
            return (my_strdup(tmp->value));
        tmp = tmp->next;
    }
    return (NULL);
}

void check_oldpwd(linked_list_t *list)
{
    size_t buf_size = 200;
    char *buffer = malloc(sizeof(char) * (buf_size + 1));
    char *env_oldpwd;
    char *oldpwd = get_env_value(list, "OLDPWD");
    char *pwd;

    if (oldpwd == NULL) {
        pwd = getcwd(buffer, buf_size);
        env_oldpwd = malloc(sizeof(char) * (my_strlen
                                    (pwd) + my_strlen("setenv OLDPWD ") + 1));
        env_oldpwd = my_strcpy(env_oldpwd, "setenv OLDPWD ");
        env_oldpwd = my_strcat(env_oldpwd, pwd);
        env_oldpwd[my_strlen(pwd) + my_strlen("setenv OLDPWD") + 1] = 0;
        my_setenv(env_oldpwd, list);
    }
}

char *get_pwd(linked_list_t *list)
{
    size_t buf_size = 200;
    char *buffer = malloc(sizeof(char) * (buf_size + 1));
    char *env_pwd;
    char *pwd = get_env_value(list, "PWD");

    check_oldpwd(list);
    if (pwd != NULL)
        return (pwd);
    pwd = getcwd(buffer, buf_size);
    env_pwd = malloc(sizeof(char) * (my_strlen
                                (pwd) + my_strlen("setenv PWD") + 2));
    env_pwd = my_strcpy(env_pwd, "setenv PWD ");
    env_pwd = my_strcat(env_pwd, pwd);
    env_pwd[my_strlen(pwd) + my_strlen("setenv PWD") + 1] = 0;
    my_setenv(env_pwd, list);
    return (pwd);
}

char *get_home(linked_list_t *list)
{
    char *home = get_env_value(list, "HOME");

    if (home == NULL) {
        my_putstr("no $home variable set\n");
        return (NULL);
    }
    return (home);
}

char *get_oldpwd(linked_list_t *list)
{
    char *oldpwd = get_env_value(list, "OLDPWD");

    if (oldpwd == NULL) {
        my_putstr("no $oldpwd variable set\n");
        return (NULL);
    }
    return (oldpwd);
}