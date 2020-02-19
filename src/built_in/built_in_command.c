/*
** EPITECH PROJECT, 2020
** build in command
** File description:
** checks if the input is a built in command and calls it
** (uses a function pointer)
*/

#include "minishell.h"

int print_env(char __attribute__((unused)) *input, linked_list_t *list)
{
    node_t *tmp = list->head;
    char **env = list_to_arr(list);

    if (env == NULL) {
        write(2, "Malloc at list to array failed\n", 32);
        return (ERR);
    }
    while (tmp != NULL) {
        if (tmp->variable != NULL) {
            my_putstr(tmp->variable);
            my_putchar('=');
        }
        if (tmp->value != NULL)
            my_putstr(tmp->value);
        my_putchar('\n');
        tmp = tmp->next;
    }
    free_tab(env);
    return (0);
}

int command_index(char *input)
{
    char *command_arr[4] = {"cd", "env", "setenv", "unsetenv"};
    int count = 0;
    char **command = my_str_to_word_array(input, " ");

    while (count < 4) {
        if (my_strcmp(command[0], command_arr[count]) == 0) {
            free_tab(command);
            return (count);
        }
        count++;
    }
    free_tab(command);
    return (-1);
}

func_ptr_t *ptr_func(void)
{
    func_ptr_t *flag;

    flag = malloc(sizeof(func_ptr_t) * (4));
    if (flag == NULL)
        return (NULL);
    flag[0] = &change_dir;
    flag[1] = &print_env;
    flag[2] = &my_setenv;
    flag[3] = &my_unsetenv;
    return (flag);
}

command_t built_in_command(linked_list_t *list, char *input, command_t command)
{
    char **env = list_to_arr(list);
    int index = command_index(input);
    func_ptr_t *flag_ptr = ptr_func();

    if (index != -1) {
        command.return_value = flag_ptr[index](input, list);
        command.command_status = DONE;
    }
    free_tab(env);
    return (command);
}