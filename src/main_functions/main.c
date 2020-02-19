/*
** EPITECH PROJECT, 2020
** main function for minishell
** File description:
** main
*/

#include "minishell.h"

int main(int __attribute__((unused)) ac,
                                char __attribute__((unused))**av, char **env)
{
    int return_value = 0;

    if (env == NULL || env[0] == NULL || env[0][0] == 0)
        return (ERR);
    return_value = minishell(env);
    if (return_value == ERR)
        return (ERR);
    return (return_value);
}