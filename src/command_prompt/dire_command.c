/*
** EPITECH PROJECT, 2020
** dire command
** File description:
** executes the command if there is a directory in the command
*/

#include "minishell.h"

command_t simple_dir(linked_list_t *list, char *input, command_t command)
{
    char *PWD;
    int return_value = 0;

    if (my_strncmp(input, "./", 1) != 0)
        return (command);
    PWD = get_pwd(list);
    return_value = change_dir_normal(list, input, PWD);
    if (return_value == SUCCESS) {
        command.return_value = return_value;
        command.command_status = DONE;
        return (command);
    }
    return (command);
}

/*
** if the command is just a directory we use change dire on it
*/

command_t check_is_dire_command(linked_list_t *list, char *input,
                                                        command_t command)
{
    command = simple_dir(list, input, command);
    if (command.command_status == DONE)
        return (command);
    return (command);
}