/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main call file
*/

#include <signal.h>
#include "minishell.h"

/*
** if the program exits we must free the list and every string in the list
*/

void free_env_list(linked_list_t *env_list)
{
    node_t *tmp = env_list->head;
    node_t *save_tmp;

    while (tmp->next != NULL) {
        free(tmp->value);
        free(tmp->variable);
        save_tmp = tmp;
        tmp = tmp->next;
        free(save_tmp);
    }
}

/*
** when the signal sigint is spotted, we print the prompt
*/

void ignore( __attribute__((unused)) int signal)
{
    my_putchar('\n');
    my_putstr("$> ");
    return;
}

/*
** let's create the command prompt
** clean the string given as parametter
** get the command / the flags / the args
** add the PATH found in env to it
** we should create a linked list to stock the env variables values
*/

int minishell(char **env)
{
    command_t command =
            {.input = NULL, .return_value = 0, .command_status = IN_PROGRESS};
    linked_list_t *env_list = create_env_list(env);

    while (my_strcmp(command.input, "EXIT") != 0) {
        if (isatty(0) == 1)
            my_putstr("$> ");
        if (signal(SIGINT, SIG_IGN) != SIG_IGN)
            signal(SIGINT, ignore);
        command = command_prompt(env_list, command);
    }
    if (my_strcmp(command.input, "EXIT") == 0) {
        free_env_list(env_list);
        free(env_list);
        if (isatty(0) == 1)
            my_putstr("exit\n");
    }
    return (command.return_value);
}
