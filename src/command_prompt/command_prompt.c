/*
** EPITECH PROJECT, 2020
** command prompt
** File description:
** gets the command and call the right programm
*/

#include <stdio.h>
#include <sys/wait.h>
#include "minishell.h"

/*
** Here we will start the command prompt, we need to copy the env
** and work with the copy.
** in case the user wants to modify something we must do it on the copy.
** First thing to do is to clean the string in case there is too many spaces.
** after that, to execute the command we should open the paths stocked in PATH
** in env (the copy)
** and if the exec of the command exist, fork and exevcve it with the correct
** args taken from the prompt
** to make the setenv special command easier, we will copy the env varibles in
** a linked_list to avoid reallocation of tabs
*/

int check_buffer(char *buffer)
{
    int count = 0;

    while (buffer[count] != 0) {
        if (buffer[count] != ' ' && buffer[count] != '\n'
                                        && buffer[count] != '\t')
            return (SUCCESS);
        count++;
    }
    return (ERR);
}

char *get_input(void)
{
    char *buffer;
    ssize_t read_size = 0;
    size_t bufsize = 32;

    buffer = malloc(sizeof(char) * (bufsize + 1));
    if (buffer == NULL)
        return (NULL);
    read_size = getline(&buffer, &bufsize, stdin);
    if (read_size == -1)
        return ("EXIT");
    if (check_buffer(buffer) == ERR)
        return (NULL);
    buffer = format_string(buffer);
    return (buffer);
}

/*
** the command prompt is an almost empty line that waits for you to put an input
** once you pressed enter, it will be interpreted and if possible executed
** if you press ctrl d, the minishell with exit
*/

void free_input(char **args, char *input)
{
    int count = 0;

    free(input);
    while (args[count] != NULL) {
        free(args[count]);
        count++;
    }
}

/*
** the shell can execute commands such as "./directory_name" and
** enter in the directory
*/

command_t exec_input(linked_list_t *list, char *input, command_t command)
{
    command = check_is_dire_command(list, input, command);
    if (command.command_status == DONE)
        return (command);
    command = built_in_command(list, input, command);
    if (command.command_status == DONE)
        return (command);
    else {
        command.return_value = exec_command(list, input);
        command.command_status = DONE;
        return (command);
    }
}

command_t command_prompt(linked_list_t *list, command_t command)
{
    command.input = get_input();
    command.command_status = IN_PROGRESS;
    if (my_strcmp(command.input, "EXIT") == 0)
        return (command);
    if (command.input != NULL) {
        command.input = clean_string(command.input);
        if ((my_strncmp(command.input, "exit", 4) == 0)
        || (my_strncmp(command.input, "exit ", 4) == 0)) {
            command = exit_shell(command);
            return (command);
        }
        command = exec_input(list, command.input, command);
        if (command.return_value == ERR) {
            command.input = NULL;
            return (command);
        }
    }
    return (command);
}
