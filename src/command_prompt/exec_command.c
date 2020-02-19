/*
** EPITECH PROJECT, 2020
** exec command
** File description:
** execute the command given with flags and args
*/

#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include "minishell.h"

char *check_command(char *input)
{
    DIR *directory;
    struct dirent *directory_data = NULL;
    char *copy = my_strscpy(input);

    if (input == NULL)
        return (NULL);
    copy += 2;
    directory = opendir(".");
    if (directory != NULL)
        directory_data = readdir(directory);
    while (directory_data != NULL) {
        if (my_strcmp(copy, directory_data->d_name) == 0) {
            closedir(directory);
            return (input);
        }
        directory_data = readdir(directory);
    }
    closedir(directory);
    return (NULL);
}

int exec_bin_command(char *command_path, char **args, char **env,
                                                    int is_dire_command)
{
    int return_value = 0;
    char *command = malloc(sizeof(char) * (my_strlen
                            (command_path) + my_strlen(args[0]) + 2));

    if (my_strncmp(command_path, "./", 1) != 0 && is_dire_command != TRUE) {
        command = my_strcpy(command, command_path);
        command[my_strlen(command_path)] = '/';
        command[my_strlen(command_path) + 1] = 0;
        command = my_strcat(command, args[0]);
    }
    else
        command = my_strdup(args[0]);
    return_value = execve(command, args, env);
    if (return_value == -1) {
        write(2, "excve failed", 13);
        return (ERR);
    }
    free(command);
    return (SUCCESS);
}

int fork_command(char *command_path, char **args, linked_list_t *list,
                                                        int is_dire_command)
{
    int id = fork();
    int return_value = 0;
    int status = 0;
    char **env = list_to_arr(list);

    if (id == -1)
        return (ERR);
    if (id == 0) {
        return_value = exec_bin_command(command_path, args, env,
                                                            is_dire_command);
        if (return_value == ERR) {
            return_value = kill(getpid(), SIGKILL);
            return (return_value);
        }
    }
    if (waitpid(id, &status, 0) == -1)
        return (ERR);
    free_tab(env);
    return (status);
}

int check_dire_command(char *input)
{
    int count = 0;

    while (input[count] != 0) {
        if (input[count] == '/' && count != 1)
            return (TRUE);
        count++;
    }
    return (FALSE);
}

int exec_command(linked_list_t *list, char *input)
{
    char **args = my_str_to_word_array(input, " ");
    char *command_path = my_strdup(input);
    int status = 0;
    int exec_return = 0;
    int is_dire_command = check_dire_command(input);

    if (my_strncmp(input, "./", 1) != 0 && is_dire_command != TRUE)
        command_path = get_command_path(args, list);
    else if (is_dire_command != TRUE)
        command_path = check_command(command_path);
    exec_return = print_errors(args[0], command_path);
    if (exec_return != SUCCESS)
        return (exec_return);
    else {
        status = fork_command(command_path, args, list, is_dire_command);
        if (status == ERR || status == -1)
            return (ERR);
        exec_return = print_end_status(status);
    }
    return (exec_return);
}