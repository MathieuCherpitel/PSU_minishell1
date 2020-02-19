/*
** EPITECH PROJECT, 2020
** change dir
** File description:
** reproduce the behavior of cd
*/

#include "minishell.h"

char *get_dir(char *input)
{
    while (input[0] != ' ')
        input++;
    input++;
    return (input);
}

int check_word_count(char *input, linked_list_t *list)
{
    int count = 0;
    int count_word = 0;

    while (input[count] != 0) {
        if (input[count] == ' ')
            count_word++;
        count++;
    }
    if (count_word > 1) {
        my_putstr("cd: Too many arguments.\n");
        return (ERR);
    }
    if (count_word == 0) {
        call_options("~", list);
        return (0);
    }
    return (-1);
}

/*
**  when only cd go back to HOME in env
**  when cd - old pwd becomes pwd && pwd becomes old pwd
**  else cd pwd becomes input && pwd old becomes pwd
*/

int call_options(char *directory, linked_list_t *list)
{
    char *PWD = get_pwd(list);
    char *HOME;
    char *OLDPWD;

    if (my_strcmp(directory, "~") == 0) {
        HOME = get_home(list);
        if (HOME == NULL)
            return (1);
        return (change_dir_home(list, HOME, PWD));
    }
    if (my_strcmp(directory, "-") == 0) {
        OLDPWD = get_oldpwd(list);
        if (OLDPWD == NULL)
            return (1);
        return (change_dir_old(list, OLDPWD, PWD));
    }
    else
        return (change_dir_normal(list, directory, PWD));
    return (0);
}

int change_dir(char *input, linked_list_t *list)
{
    char *directory;
    int return_value = 0;
    int correct_dir = SUCCESS;
    int return_word_count = check_word_count(input, list);

    if (return_word_count != -1)
        return (return_word_count);
    directory = get_dir(input);
    if (my_strcmp(directory, "-") != 0 && my_strcmp(directory, "~") != 0)
        correct_dir = check_dir(directory);
    if (correct_dir != SUCCESS) {
        error_change_dir(correct_dir, directory);
        return (1);
    }
    return_value = call_options(directory, list);
    return (return_value);
}