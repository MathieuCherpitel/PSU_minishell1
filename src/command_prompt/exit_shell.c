/*
** EPITECH PROJECT, 2020
** exit shell
** File description:
** if the command is input check it's args
*/

#include "minishell.h"

char *remove_enter(char *arg)
{
    int count = 0;

    while (arg[count] != '\n')
        count++;
    arg[count] = 0;
    return (arg);
}

int get_tab_size(char **tab)
{
    int tab_size = 0;

    while (tab[tab_size] != NULL)
        tab_size++;
    return (tab_size);
}

int check_exit_arg(char *arg)
{
    if (arg[0] == '-')
        arg++;
    if (arg[0] >= 48 && arg[0] <= 57) {
        if (my_isnum(arg) == 0) {
            my_putstr("exit: Badly formed numbed.\n");
            return (ERR);
        }
    }
    else {
        if (my_isnum(arg) == 0) {
            my_putstr("exit: Expression Syntax.\n");
            return (ERR);
        }
    }
    return (0);
}

command_t exit_shell(command_t command)
{
    char **args = my_str_to_word_array(command.input, " ");
    int tab_size = get_tab_size(args);
    int exit_arg = 0;

    if (tab_size == 1) {
        command.return_value = 0;
        command.input = "EXIT";
        return (command);
    }
    if (tab_size > 2) {
        command.return_value = ERR;
        my_putstr("exit: Expression Syntax.\n");
        return (command);
    }
    exit_arg = check_exit_arg(args[1]);
    if (exit_arg == 0) {
        command.input = "EXIT";
        command.return_value = my_getnbr(args[1]);
    }
    return (command);
}